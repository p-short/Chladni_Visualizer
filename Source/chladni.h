/*
  ==============================================================================

    chladni.h
    Created: 18 Aug 2022 11:19:33am
    Author:  Phillip Short

  ==============================================================================
*/

#pragma once

#include <cmath>
#include <random>

const float pi = 3.14159265359;

//method that produces the shapes for the particle system to follow
float chladni(float x, float y, float a, float b, float m, float n)
{
    return a * sin(pi * n * x) * sin(pi * m * y) + b * sin(pi * m * x) * sin(pi * n * y);
}

//method to get a random float within any range (including negative numbers)
float randFloatInRange(float n1, float n2)
{
    std::uniform_real_distribution<double> dist {n1, n2};
    std::mt19937 mt {std::random_device()()};
    return dist(mt);
}

