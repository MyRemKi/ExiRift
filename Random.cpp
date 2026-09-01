#include "Random.h"

std::mt19937& Random::engine()
{
    static std::mt19937 eng(std::random_device{}());
    return eng;
}

int Random::getInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(engine());
}

float Random::getFloat(float min, float max)
{
    std::uniform_real_distribution<float> dist(min, max);
    return dist(engine());
}

bool Random::rollChance(float chance)
{
    return getFloat(0.0f, 1.0f) < chance;
}