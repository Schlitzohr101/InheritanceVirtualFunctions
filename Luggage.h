#ifndef LUGGAGE_H
#define LUGGAGE_H
#include <string>
#include <math.h>
class Luggage {
    private:
        std::string type;
    public:
        virtual float volume() = 0;
        std::string getType();
        void setType(std::string);
};

std::string Luggage::getType() {
    return type;
}

void Luggage::setType(std::string temp) {
    type = temp;
}

#endif