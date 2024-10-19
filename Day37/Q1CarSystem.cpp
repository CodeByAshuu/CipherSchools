#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string brand;
    string model;
    int year;
    int speed;

public:
    Car(string b, string m, int y) : brand(b), model(m), year(y), speed(0) {}

    string getBrand() const {
        return brand;
    }

    string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    int getSpeed() const {
        return speed;
    }

    void setSpeed(int s) {
        speed = (s >= 0) ? s : 0;
    }

    void increaseSpeed(int amount) {
        speed += amount;
    }

    void decreaseSpeed(int amount) {
        speed = (speed - amount >= 0) ? speed - amount : 0;
    }

    void displayDetails() const {
        cout << "Brand: " << brand << ", Model: " << model
             << ", Year: " << year << ", Current Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 2020);

    myCar.displayDetails();

    myCar.increaseSpeed(50);
    cout << "After increasing speed by 50 km/h:" << endl;
    myCar.displayDetails();

    myCar.decreaseSpeed(20);
    cout << "After decreasing speed by 20 km/h:" << endl;
    myCar.displayDetails();

    myCar.decreaseSpeed(40);
    cout << "After trying to decrease speed by 40 km/h (should not go below 0):" << endl;
    myCar.displayDetails();

    return 0;
}
