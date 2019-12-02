#include "Cube.h"
#include "Box.h"
#include "Cylinder.h"
#include "Dodecahedron.h"
#include "RhombicDodecahedron.h"
#include "Octahedron.h"
#include "Pyramid.h"
#include "Sphere.h"
#include <map>
#include <iostream>
using namespace std;

typedef void (*voidFuncPtr)(map<int,Luggage *>&);

voidFuncPtr Choices(int);

void printMenu();
void showAll(map<int,Luggage *>&);
void addLuggage(map<int,Luggage *>&);
void luggageOptions();
void removeLuggage(map<int,Luggage *>&);
