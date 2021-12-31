#pragma once

#include <PerlinNoise.hpp>
#include <iostream>
#include <raylib.h>
#include <thread>
#include <vector>

class Map
{
private:
    int sizeY;
    int sizeX;
    int oct;
    double **mapData;
    RenderTexture2D mapTexture;
    siv::PerlinNoise::seed_type seed;
    siv::PerlinNoise perlin;

public:
    void recreateMap();
    void displayMap(int, bool);
    Map(int x, int y, int oct);
    ~Map();
};
