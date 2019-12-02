#ifndef PYRAMID_H
#define PYRAMID_H
#include "Luggage.h"
class Pyramid : public Luggage {
    private:
        float baseLen, height;
    public:
        Pyramid(int, int);
        Pyramid(float, float);
        float volume() override;
};

Pyramid::Pyramid(int s, int h) {
    setType("Pyramid");
    baseLen = float(s);
    height = float(h);
}

Pyramid::Pyramid(float s, float h) {
    setType("Pyramid");
    baseLen = s;
    height = h;
}

float Pyramid::volume() {
    return height * pow(baseLen, 2.0) * 1.0/3;
}

#endif