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
};

class Car : public Vehicle {
public:
    void calculateTime(double distance) const override {
        double time = distance / getSpeed(); 
        cout << "Car Model: " << getModel() << endl;
        cout << "Time to travel " << distance << " km: " << time << " hours" << endl;
    }
};

class Bike : public Vehicle {
public:
    void calculateTime(double distance) const override {
        double time = distance / getSpeed();
        cout << "Bike Model: " << getModel() << endl;
        cout << "Time to travel " << distance << " km: " << time << " hours" << endl;
    }
};

int main() {
    Car car;
    car.setModel("Toyota Fortuner");
    car.setSpeed(80); 

    Bike bike;
    bike.setModel("Yamaha FZ");
    bike.setSpeed(60); 

    double distance = 240;

    cout << "=== Car Calculation ===" << endl;
    car.calculateTime(distance);

    cout << "\n=== Bike Calculation ===" << endl;
    bike.calculateTime(distance);

}
/*output
=== Car Calculation ===
Car Model: Toyota Fortuner
Time to travel 240 km: 3 hours

=== Bike Calculation ===
Bike Model: Yamaha FZ
Time to travel 240 km: 4 hours

*/
