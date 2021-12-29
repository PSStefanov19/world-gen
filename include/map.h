#pragma once

#include <PerlinNoise.hpp>
#include <iostream>
#include <raylib.h>

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

class Map
{
private:
    int sizeY;
    int sizeX;
    int oct;
    double **mapData;
    siv::PerlinNoise::seed_type seed;
    siv::PerlinNoise perlin;

public:
    void createMap();
    void displayMap();
    Map(int y, int x, int octaves);
    ~Map();
};
