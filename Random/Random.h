#ifndef RANDOM_H
#define RANDOM_H

#pragma once

#include <random>

class Random
{
public:
    // Entier aleatoire dans [min, max] (bornes incluses)
    static int getInt(int min, int max);

    // Flottant aleatoire dans [min, max)
    static float getFloat(float min, float max);

    // true avec une probabilite "chance" (0.0 a 1.0), utile pour un taux de drop
    static bool rollChance(float chance);

private:
    static std::mt19937& engine();
};

#endif