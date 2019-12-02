#ifndef SPHERE_H
#define SPHERE_H
#include "Luggage.h"

class Sphere : public Luggage {
    private:
        float r;
    public:
        Sphere(float);
        Sphere(int);
        float volume() override;
};

Sphere::Sphere(float radius) {
    setType("Sphere");
    r = radius;
}

Sphere::Sphere(int radius) {
    setType("Sphere");
    r = float(radius);
}

float Sphere::volume() {
    return float(4)/3 * M_PI * pow(r,3.0);
}

#endif