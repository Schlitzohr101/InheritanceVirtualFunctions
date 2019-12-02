#ifndef RHOMBIC_DODECAHEDRON_H
#define RHOMBIC_DODECAHEDRON_H
#include "Luggage.h"
class RhombicDodecahedron : public Luggage {
    private:
        float edgeLen;
    public:
        RhombicDodecahedron(int);
        RhombicDodecahedron(float);
        float volume() override;
};

RhombicDodecahedron::RhombicDodecahedron(int s) {
    setType("RhombicDodecahedron");
    edgeLen = float(s);
}

RhombicDodecahedron::RhombicDodecahedron(float s) {
    setType("RhombicDodecahedron");
    edgeLen = s;
}

float RhombicDodecahedron::volume() {
    return (16 * sqrt(3.0))/9 * pow(edgeLen, 3.0);
}
#endif