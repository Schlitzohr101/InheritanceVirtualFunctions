#include "header.h"
int main()
{
    map<int,Luggage * > storage;
    voidFuncPtr method;
    int select = 0;
    printMenu();
    cin >> select;
    while (select != 4)
    {
        method = Choices(select);
        method(storage);
        printMenu();
        cin >> select;
    }
    
    cout << "Have a nice day!\n";

    return 0;
}

voidFuncPtr Choices(int x) {
    map<const int,voidFuncPtr> choices {
        {1,addLuggage},
        {2,removeLuggage},
        {3,showAll},
    };
    return choices[x];
}

void printMenu() {
    cout << "1) Add Luggage to storage container\n"
         << "2) Remove Luggage from storage container\n"
         << "3) Show all Luggage\n"
         << "4) Quit" << endl;
}

void showAll(map<int,Luggage * > &temp) {
    map<int,Luggage *>::iterator it;
    float totalVol = 0;
    cout << "Storage Containers Contents :\n";
    if (!temp.empty()) {
        for (it = temp.begin(); it != temp.end(); it++) {
            totalVol += it->second->volume();
            cout << it->second->getType() << " : " << it->second->volume() << endl;
        }
        cout << "total items: " << temp.size() << " - volume: " << totalVol << endl;
    } else {
        cout << "Empty" << endl;
    }
}

void addLuggage(map<int,Luggage *> &temp) {
    int choice = 0;
    do
    {
        luggageOptions();
        cin >> choice;
        if (choice < 1 || choice > 8)
        {
            cout << "Please choose a choice on the menu provided\n\n";
        }
    } while (choice < 1 || choice > 8);
    float radius = 0;
    float width = 0;
    float height = 0;
    float length = 0;
    float edge = 0;
    switch (choice)
    {
    case 1:
        cout << "For your box:\nWhat width? ";
        
        cin >> width;
        cout << "What height? ";
        
        cin >> height;
        cout << "What length? ";
        
        cin >> length;
        temp[temp.size()+1] = new Box(length, width, height);
        break;
    case 2: 
        cout << "For your cube:\nWhat size edge? ";
        
        cin >> edge;
        temp[temp.size()+1] = new Cube(edge);
        break;
    case 3: 
        cout << "For your Sphere:\nWhat radius? ";
        
        cin >> radius;
        temp[temp.size()+1] = new Sphere(radius);
        break;
    case 4:
        cout << "For your Cylinder:\nWhat radius? ";
        cin >> radius;
        cout << "What height? ";
        cin >> height;
        temp[temp.size()+1] = new Cylinder(radius,height);
        break;
    case 5:
        cout << "For your Pyramid:\nWhat size base edge? ";
        cin >> edge;
        cout << "What height? ";
        cin >> height;
        temp[temp.size()+1] = new Pyramid(edge,height);
        break;
    case 6:
        cout << "For your Octahedron:\nWhat size edge? ";
        cin >> edge;
        temp[temp.size()+1] = new Octahedron(edge);
        break;
    case 7:
        cout << "For your Dodecahedron:\nWhat size edge? ";
        cin >> edge;
        temp[temp.size()+1] = new Dodecahedron(edge);
        break;
    default:
        cout << "For your Rhombic Dodecahedron:\nWhat size edge? ";
        cin >> edge;
        temp[temp.size()+1] = new RhombicDodecahedron(edge);
        break;
    }
}

void luggageOptions() {
    cout << "1) Box\n"
         << "2) Cube\n"
         << "3) Sphere\n"
         << "4) Cylinder\n"
         << "5) Pyramid\n"
         << "6) Octahedron\n"
         << "7) Dodecahedron\n"
         << "8) Rhombic Dodecahedron\n";
}

void removeLuggage(map<int, Luggage *> &temp) {
    for (auto &&itr : temp) {
        cout << itr.first << ") " << itr.second->getType() << endl;
    }
    int rmv = 0;
    do
    {
        cout << "Which Luggage to remove?\n: ";
        cin >> rmv;
        if (rmv < 1 || rmv > temp.size()) {
            cout << "Please enter a number given above\n\n";
        }
    } while (rmv < 1 || rmv > temp.size());
    temp.erase(rmv);
}