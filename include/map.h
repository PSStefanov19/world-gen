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
    siv::PerlinNoise::seed_type seed;
    siv::PerlinNoise perlin;

public:
    void recreateMap();
    void displayMap(int);
    Map(int y, int x, int octaves);
    ~Map();
};
