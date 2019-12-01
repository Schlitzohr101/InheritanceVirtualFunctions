#ifndef PYRAMID_H
#define PYRAMID_H
#include "Luggage.h"
class Pyramid : public Luggage {
    private:
        float length, width, height;
    public:
        Pyramid(int, int, int);
        Pyramid(float, float, float);
        float volume() override;
};

Pyramid::Pyramid(int s, int, int)

#endif