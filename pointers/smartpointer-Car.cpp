#include <iostream>
#include <memory>

using namespace std;

class Car
{
    string color;
    int numDoors;

    public:
        Car(string color, int numDoors)
        {
            this->color = color;
            this ->numDoors = numDoors;
        }

        string getColor()
        {
            return color;
        }

        int getNumDoors()
        {
            return numDoors;
        }      
};

int main()
{
    auto myCar = make_unique<Car>("red", 4);

    cout<<"Car Description: "<<endl;
    cout<<"1.Color: "<<myCar->getColor()<<" \t2.Doors: " <<myCar->getNumDoors()<<endl;

    return 0;
}
