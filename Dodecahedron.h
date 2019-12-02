#ifndef DODECAHEDRON_H
#define DODECAHEDRON_H
#include "Luggage.h"
class Dodecahedron : public Luggage {
    private:
        float edgeLen;

    public:
        Dodecahedron(int);
        Dodecahedron(float);
        float volume() override;
};

Dodecahedron::Dodecahedron(int s) {
    setType("Dodecahedron");
    edgeLen = float(s);
}

Dodecahedron::Dodecahedron(float s) {
    setType("Dodecahedron");
    edgeLen = s;
}


float Dodecahedron::volume() {
    return 1.0/4 * (15 + 7*sqrt(5.0)) * pow(edgeLen, 3.0);
}
#endif