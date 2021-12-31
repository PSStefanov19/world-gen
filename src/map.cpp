#include "map.h"

void Map::recreateMap()
{
    seed = rand();
    perlin.reseed(seed);

    std::vector<std::thread> thread_pool;

    for (int y = 0; y < sizeY; y++)
    {
        thread_pool.push_back(std::move(std::thread([&](int y, int oct)
        {
            for (int x = 0; x < sizeX; x++)
            {
                mapData[y][x] = perlin.octave2D_01((x * 0.01), (y * 0.01), oct);
            }
        }, y, oct)));
    }

    for (std::thread &th : thread_pool)
    {
        if (th.joinable())
            th.join();
    }
    thread_pool.clear();

    BeginTextureMode(mapTexture);
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            DrawPixel(x, y, {
                (unsigned char)(mapData[y][x] * 255),
                (unsigned char)(mapData[y][x] * 255),
                (unsigned char)(mapData[y][x] * 255),
                255
            });
        }
    }
    EndTextureMode();
}

void Map::displayMap(bool software_renderer)
{
    if (software_renderer)
    {
        for (int i = 0; i < sizeY; i++)
        {
            for (int j = 0; j < sizeX; j++)
            {
                if (mapData[i][j] <= 0.40)
                {
                    DrawRectangle(j * scale, i * scale, scale, scale, BLUE);
                }
                else if (mapData[i][j] > 0.40 && mapData[i][j] < 0.70)
                {
                    DrawRectangle(j * scale, i * scale, scale, scale, GREEN);
                }
                else
                {
                    DrawRectangle(j * scale, i * scale, scale, scale, GRAY);
                }
            }
        }
    }
    else
    {
        BeginShaderMode(renderShader);
            DrawTextureRec(
                mapTexture.texture,
                { 0, 0, (float)mapTexture.texture.width * scale, (float)-mapTexture.texture.height * scale },
                {}, WHITE
            );
        EndShaderMode();
    }
}

Map::Map(int x, int y, int octaves, int scale)
{
    // Set size of map
    this->sizeY = y / scale;
    this->sizeX = x / scale;

    // Set octaves
    this->oct = octaves;

    // Set scaling
    this->scale = scale;

    // Initialize map matrix
    mapData = new double *[sizeY];
    for (int i = 0; i < sizeY; i++)
    {
        mapData[i] = new double[sizeX];
    }

    // Load shaders used for hardware rendering
    renderShader = LoadShader(NULL, "res/map_render.fs");
    int scaleLoc = GetShaderLocation(renderShader, "scale");
    SetShaderValue(renderShader, scaleLoc, &(this->scale), SHADER_UNIFORM_INT);
    
    // Initialize map matrix (for GPU)
    mapTexture = LoadRenderTexture(sizeX, sizeY);

    // Populate map
    recreateMap();
}

Map::~Map()
{
    for (int i = 0; i < sizeY; i++)
    {
        delete[] mapData[i];
    }
    delete[] mapData;
    UnloadRenderTexture(mapTexture);
    UnloadShader(renderShader);
}
