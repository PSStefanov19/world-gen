#include "map.h"

void Map::createMap()
{
    mapData = new double *[sizeY];
    for (int i = 0; i < sizeY; i++)
    {
        mapData[i] = new double[sizeX];
    }

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            mapData[y][x] = perlin.octave2D_01((x * 0.01), (y * 0.01), oct + 30);
        }
    }
}

void Map::displayMap()
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            if (mapData[i][j] <= 0.40)
            {
                DrawRectangle(j * 2, i * 2, j * 2, i * 2, BLUE);
            }
            else if (mapData[i][j] > 0.40 && mapData[i][j] < 0.70)
            {
                DrawRectangle(j * 2, i * 2, j * 2, i * 2, GREEN);
            }
            else
            {
                DrawRectangle(j * 2, i * 2, j * 2, i * 2, GRAY);
            }
        }
    }
}

Map::Map(int y, int x, int octaves)
{
    // Set size of map
    this->sizeY = y;
    this->sizeX = x;

    // Set octaves
    this->oct = octaves;

    // Pick random seed
    srand(time(NULL));
    seed = rand();

    // Reseed perlin noise
    perlin.reseed(seed);
}

Map::~Map()
{
    for (int i = 0; i < sizeY; i++)
    {
        delete[] mapData[i];
    }
    delete[] mapData;
}
