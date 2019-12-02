#ifndef OCTAHEDRON_H
#define OCTAHEDRON_H
#include "Luggage.h"
class Octahedron : public Luggage {
    private:
        float edgeLen;
    
    public:
        Octahedron(int);
        Octahedron(float);
        float volume() override;
};

Octahedron::Octahedron(int s) {
    setType("Octahedron");
    edgeLen = float(s);
}

Octahedron::Octahedron(float s) {
    setType("Octahedron");
    edgeLen = s;
}

float Octahedron::volume() {
    return 1.0/3 * sqrt(2.0) * pow(edgeLen, 3.0);
}
#endif