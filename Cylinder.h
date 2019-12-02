#ifndef CYLINEDR_H
#define CYLINDER_H
#include "Luggage.h"
class Cylinder : public Luggage {
    private:
        float radius, length;
    
    public:
        Cylinder(int,int);
        Cylinder(float,float);
        float volume() override;
};

Cylinder::Cylinder(int r, int l) {
    setType("Cylinder");
    radius = float(r);
    length = float(l);
}

Cylinder::Cylinder(float r, float l) {
    setType("Cylinder");
    radius = r;
    length = l;
}

float Cylinder::volume() {
   return M_PI * pow(radius, 2.0) * length;
}

#endif