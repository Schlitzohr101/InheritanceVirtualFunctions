#ifndef BOX_H
#define BOX_H
#include "Luggage.h"

class Box : public Luggage
{
    private:
        float length, width, height;    
public:
    Box(int, int, int);
    Box(float,float,float);
    float volume() override;
};

Box::Box(int s, int s1, int s2)
{
    setType("Box");
    length = float(s);
    width = float(s1);
    height = float(s2);
}

Box::Box(float s, float s1,float s2) {
    setType("Box");
    length = s;
    width = s1;
    height = s2;
}

float Box::volume() {
    return length * width * height;
}


#endif