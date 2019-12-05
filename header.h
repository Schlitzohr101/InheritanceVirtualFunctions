#ifndef HEADER_H
#define HEADER_H
#include "Cube.h"
#include "Box.h"
#include "Cylinder.h"
#include "Dodecahedron.h"
#include "RhombicDodecahedron.h"
#include "Octahedron.h"
#include "Pyramid.h"
#include "Sphere.h"
#include <map>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <limits>
using namespace std;

typedef void (*voidFuncPtr)(vector<Luggage *>&);

voidFuncPtr Choices(int);

void printMenu();
void showAll(vector<Luggage *>&);
void addLuggage(vector<Luggage *>&);
void luggageOptions();
void removeLuggage(vector<Luggage *>&);

#endif