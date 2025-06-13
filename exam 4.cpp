#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string model;
    double speed;

public:
   
    void setModel(string m) {
        model = m;
    }

    void setSpeed(double s) {
        if (s > 0)
            speed = s;
        else
            cout << "Speed must be positive." << endl;
    }

    string getModel() const {
        return model;
    }

    double getSpeed() const {
        return speed;
    }

    virtual void calculateTime(double distance) const = 0;

    virtual void displayDetails() const = 0;

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void calculateTime(double distance) const override {
        double time = distance / getSpeed();
        cout << "Car will take " << time << " hours to cover " << distance << " km.\n";
    }

    void displayDetails() const override {
        cout << "[Car Details]\n";
        cout << "Model: " << getModel() << "\nSpeed: " << getSpeed() << " km/h\n";
    }
};

class Bike : public Vehicle {
public:
    void calculateTime(double distance) const override {
        double time = distance / getSpeed();
        cout << "Bike will take " << time << " hours to cover " << distance << " km.\n";
    }

    void displayDetails() const override {
        cout << "[Bike Details]\n";
        cout << "Model: " << getModel() << "\nSpeed: " << getSpeed() << " km/h\n";
    }
};

int main() {
  
    Car* car1 = new Car();
    car1->setModel("Hyundai Creta");
    car1->setSpeed(100);

    Bike* bike1 = new Bike();
    bike1->setModel("Royal Enfield");
    bike1->setSpeed(70);

    Vehicle* vehicles[2];
    vehicles[0] = car1;
    vehicles[1] = bike1;

    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();
        vehicles[i]->calculateTime(210);
        cout << "----------------------------\n";
    }
    delete car1;
    delete bike1;
}
/*output
[Car Details]
Model: Hyundai Creta
Speed: 100 km/h
Car will take 2.1 hours to cover 210 km.
----------------------------
[Bike Details]
Model: Royal Enfield
Speed: 70 km/h
Bike will take 3 hours to cover 210 km.
----------------------------
*/
