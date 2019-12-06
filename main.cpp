//William Murray
//CECS 282-05
//Prog - 6 Inheritance/Virtual Functions
//Nov 21, 2019
#include "header.h"
int main()
{
    vector<Luggage * > storage;
    voidFuncPtr method;
    int select = 0;

    do
    {
        printMenu();
        cin >> select;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nEnter a NUMBER on the menu above" << endl << endl;
        }
        else if (select < 1 || select > 4) {
            cerr << "\nPlease choose one of the options on the menu\n" << endl;
        }
    } while (select < 1 || select > 4);
    

    while (select != 4)
    {
        method = Choices(select);
        method(storage);
        cout << endl;
        do
        {
            printMenu();
            cin >> select;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\nEnter a NUMBER on the menu above\n" << endl;
            }
            else if (select < 1 || select > 4) {
                cout << "Please choose one of the options on the menu\n";
            }
        } while (select < 1 || select > 4);
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

void showAll(vector<Luggage * > &temp) {
    float totalVol = 0;
    cout << "Storage Containers Contents :\n";
    if (!temp.empty()) {
        for (int i = 0; i < temp.size(); i++)
        {
            totalVol += temp[i]->volume();
            cout << temp[i]->getType() << " : ";
            printf("%.4f\n",temp[i]->volume());
        }
        cout << "total items: " << temp.size() << " - volume: ";
        printf("%.4f\n\n",totalVol);
    } else {
        cout << "Empty" << endl << endl;
    }
}

void addLuggage(vector<Luggage *> &temp) {
    int choice = 0;
    do
    {
        luggageOptions();
        cin >> choice;
        if (choice < 1 || choice > 8)
        {
            cout << "\nPlease choose a choice on the menu provided\n\n";
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
        temp.push_back(new Box(length, width, height));
        break;
    case 2: 
        cout << "For your cube:\nWhat size edge? ";
        
        cin >> edge;
        temp.push_back(new Cube(edge));
        break;
    case 3: 
        cout << "For your Sphere:\nWhat radius? ";
        
        cin >> radius;
        temp.push_back(new Sphere(radius));
        break;
    case 4:
        cout << "For your Cylinder:\nWhat radius? ";
        cin >> radius;
        cout << "What height? ";
        cin >> height;
        temp.push_back( new Cylinder(radius,height));
        break;
    case 5:
        cout << "For your Pyramid:\nWhat size base edge? ";
        cin >> edge;
        cout << "What height? ";
        cin >> height;
        temp.push_back( new Pyramid(edge,height));
        break;
    case 6:
        cout << "For your Octahedron:\nWhat size edge? ";
        cin >> edge;
        temp.push_back( new Octahedron(edge));
        break;
    case 7:
        cout << "For your Dodecahedron:\nWhat size edge? ";
        cin >> edge;
        temp.push_back( new Dodecahedron(edge));
        break;
    default:
        cout << "For your Rhombic Dodecahedron:\nWhat size edge? ";
        cin >> edge;
        temp.push_back(new RhombicDodecahedron(edge));
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

void removeLuggage(vector<Luggage *> &temp) {
    vector<Luggage *>::iterator itr;
    for (int i = 0; i < temp.size(); i++)
    {
        cout << i+1 << ") " << temp[i]->getType() << endl;
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

    itr = temp.begin();

    for (int i = 1; i < rmv; i++)
    {
        itr++;
    }
    temp.erase(itr);
}