#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    int vehicleID;
    string manufacturer, model;
    int year;
    static int totalVehicles;

public:
    Vehicle() {
        vehicleID = 0;
        manufacturer = model = "";
        year = 0;
        totalVehicles++;
    }

    Vehicle(int id, string manu, string mod, int yr) {
        vehicleID = id;
        manufacturer = manu;
        model = mod;
        year = yr;
        totalVehicles++;
    }

    virtual ~Vehicle() {
        totalVehicles--;
    }

    static int getTotalVehicles() {
        return totalVehicles;
    }

    virtual void display() {
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Year: " << year << endl;
    }

    int getVehicleID() {
        return vehicleID;
    }
};
int Vehicle::totalVehicles = 0;
class Car : public Vehicle {
protected:
    string fuelType;

public:
    Car() : Vehicle() {
        fuelType = "";
    }
    Car(int id, string manu, string mod, int yr, string fuel)
        : Vehicle(id, manu, mod, yr), fuelType(fuel) {}
    void display() override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    ElectricCar() : Car() {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string manu, string mod, int yr, string fuel, int battery)
        : Car(id, manu, mod, yr, fuel), batteryCapacity(battery) {}

    void display() override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};
class Aircraft {
protected:
    int flightRange;

public:
    Aircraft() {
        flightRange = 0;
    }

    Aircraft(int range) {
        flightRange = range;
    }

    void displayAircraft() {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar() : Car(), Aircraft() {}
    FlyingCar(int id, string manu, string mod, int yr, string fuel, int range)
        : Car(id, manu, mod, yr, fuel), Aircraft(range) {}
    void display() {
        Car::display();
        Aircraft::displayAircraft();
    }
};

class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    SportsCar() : ElectricCar() {
        topSpeed = 0;
    }
    SportsCar(int id, string manu, string mod, int yr, string fuel, int battery, int speed)
        : ElectricCar(id, manu, mod, yr, fuel, battery), topSpeed(speed) {}
    void display() override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

class Sedan : public Car {
public:
    Sedan() : Car() {}

    Sedan(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}
    void display() override {
        Car::display();
        cout << "Type: Sedan" << endl;
    }
};

class SUV : public Car {
public:
    SUV() : Car() {}
    SUV(int id, string manu, string mod, int yr, string fuel)
        : Car(id, manu, mod, yr, fuel) {}
    void display() override {
        Car::display();
        cout << "Type: SUV" << endl;
    }
};

class VehicleRegistry {
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry() {
        count = 0;
    }
    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
    }
    void addVehicle() {
        int type;
        cout << "\nSelect Vehicle Type to Add:\n";
        cout << "1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\nChoice: ";
        cin >> type;

        int id, yr, battery, range, speed;
        string manu, mod, fuel;
        cout << "Enter Vehicle ID: ";
        cin >> id;
        cout << "Enter Manufacturer: ";
        cin >> manu;
        cout << "Enter Model: ";
        cin >> mod;
        cout << "Enter Year: ";
        cin >> yr;
        switch (type) {
        case 1:
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            vehicles[count++] = new Car(id, manu, mod, yr, fuel);
            break;
        case 2:
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;
            vehicles[count++] = new ElectricCar(id, manu, mod, yr, fuel, battery);
            break;
        case 3:
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Flight Range (km): ";
            cin >> range;
            vehicles[count++] = new FlyingCar(id, manu, mod, yr, fuel, range);
            break;
        case 4:
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Battery Capacity (kWh): ";
            cin >> battery;
            cout << "Enter Top Speed (km/h): ";
            cin >> speed;
            vehicles[count++] = new SportsCar(id, manu, mod, yr, fuel, battery, speed);
            break;
        case 5:
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            vehicles[count++] = new Sedan(id, manu, mod, yr, fuel);
            break;
        case 6:
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            vehicles[count++] = new SUV(id, manu, mod, yr, fuel);
            break;
        default:
            cout << "Invalid Type.\n";
        }
    }
    void displayAllVehicles() {
        cout << "\n--- All Vehicles ---\n";
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
            cout << "---------------------\n";
        }
        cout << "Total Vehicles: " << Vehicle::getTotalVehicles() << endl;
    }
    void searchById(int id) {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                cout << "\nVehicle Found:\n";
                vehicles[i]->display();
                return;
            }
        }
        cout << "Vehicle with ID " << id << " not found.\n";
    }
};

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "\n--- Vehicle Registry Menu ---\n";
        cout << "1. Add Vehicle\n2. View All Vehicles\n3. Search Vehicle by ID\n4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registry.addVehicle();
            break;
        case 2:
            registry.displayAllVehicles();
            break;
        case 3: {
            int id;
            cout << "Enter Vehicle ID to Search: ";
            cin >> id;
            registry.searchById(id);
            break;
        }
        case 4:
            cout << "Exiting Program.\n";
            break;
        default:
            cout << "Invalid Choice. Try again.\n";
        }
   } while (choice != 4);

}
/*output
--- Vehicle Registry Menu ---
1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Exit
Enter Choice: 1

Select Vehicle Type to Add:
1. Car
2. Electric Car
3. Flying Car
4. Sports Car
5. Sedan
6. SUV
Choice: 1
Enter Vehicle ID: 325453
Enter Manufacturer: tata
Enter Model: sdfg
Enter Year: 2023
Enter Fuel Type: jeguar

--- Vehicle Registry Menu ---
1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Exit
Enter Choice: 3
Enter Vehicle ID to Search: 325453

Vehicle Found:
ID: 325453, Manufacturer: tata, Model: sdfg, Year: 2023
Fuel Type: jeguar

--- Vehicle Registry Menu ---
1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Exit
Enter Choice: 2

--- All Vehicles ---
ID: 325453, Manufacturer: tata, Model: sdfg, Year: 2023
Fuel Type: jeguar
---------------------
Total Vehicles: 1

--- Vehicle Registry Menu ---
1. Add Vehicle
2. View All Vehicles
3. Search Vehicle by ID
4. Exit
Enter Choice: 4
Exiting Program.
*/
