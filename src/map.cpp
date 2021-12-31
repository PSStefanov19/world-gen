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

void Map::displayMap(int scale, bool software_renderer)
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
        DrawTextureRec(
            mapTexture.texture,
            { 0, 0, (float)mapTexture.texture.width, (float)-mapTexture.texture.height },
            {}, WHITE
        );
    }
}

Map::Map(int x, int y, int octaves)
{
    // Set size of map
    this->sizeY = y;
    this->sizeX = x;

    // Set octaves
    this->oct = octaves;

    mapData = new double *[sizeY];
    for (int i = 0; i < sizeY; i++)
    {
        mapData[i] = new double[sizeX];
    }

    mapTexture = LoadRenderTexture(sizeX, sizeY);

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
}
