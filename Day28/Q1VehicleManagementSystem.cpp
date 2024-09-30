#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    int year;
    float fuel;

public:
    Vehicle(string mk, int yr, float fl) : make(mk), year(yr), fuel(fl) {}

    void refuel(float amount) {
        fuel += amount;
        cout << make << " refueled by " << amount << " liters." << endl;
    }

    virtual void display() {
        cout << "Make: " << make << endl;
        cout << "Year: " << year << endl;
        cout << "Fuel: " << fuel << " liters" << endl;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car(string mk, int yr, float fl, int drs) : Vehicle(mk, yr, fl), doors(drs) {}

    void display() override {
        Vehicle::display();
        cout << "Number of doors: " << doors << endl;
    }

    void openDoors() {
        cout << "Doors are opened." << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasCarrier;

public:
    Bike(string mk, int yr, float fl, bool carrier) : Vehicle(mk, yr, fl), hasCarrier(carrier) {}

    void display() override {
        Vehicle::display();
        cout << "Has carrier: " << (hasCarrier ? "Yes" : "No") << endl;
    }

    void kickStart() {
        cout << "Bike kick-started." << endl;
    }
};

int main() {
    Car myCar("Toyota", 2021, 10.0, 4);
    
    Bike myBike("Honda", 2020, 5.0, true);

    myCar.refuel(5.0);
    myBike.refuel(2.0);

    cout << "\nCar details:" << endl;
    myCar.display();
    myCar.openDoors();

    cout << "\nBike details:" << endl;
    myBike.display();
    myBike.kickStart();

    return 0;
}
