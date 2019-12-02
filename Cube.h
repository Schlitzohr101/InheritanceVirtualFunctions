#ifndef CUBE_H
#define CUBE_H
#include "Luggage.h"

class Cube : public Luggage {
    private:
        float side;
    public:
        Cube(int);
        Cube(float);
        float volume() override;
};

Cube::Cube(int s) {
    setType("Cube");
    side = float(s);
}

Cube::Cube(float s) {
    setType("Cube");
    side = s;
}

float Cube::volume() {
    return pow(side,3.0);
}

#endif