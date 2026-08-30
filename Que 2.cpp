#include <iostream>
using namespace std;

// Base class
class Vehicle {
private:
    string brand;

public:
    Vehicle(string b) {
        brand = b;
    }

    void displayVehicle() {
        cout << "Brand: " << brand << endl;
    }
};

// Derived class
class Car : public Vehicle {
private:
    int speed;

public:
    Car(string b, int s) : Vehicle(b) {
        speed = s;
    }

    void displayCar() {
        displayVehicle();
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car c("Toyota", 120);

    c.displayCar();

    return 0;
}