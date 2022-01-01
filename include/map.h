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
    Vector2 position = {0, 0};
    int oct;
    int scale;
    double **mapData;
    RenderTexture2D mapTexture;
    Shader renderShader;
    siv::PerlinNoise::seed_type seed;
    siv::PerlinNoise perlin;

public:
    void recreateMap();
    void displayMap(bool);
    void zoom(bool&);
    Map(int x, int y, int oct, int scale);
    ~Map();
};
