#include <iostream>
#include <cstring>
using namespace std;


class Train {
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];
    static int trainCount;

public:

    Train() {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void setTrainNumber(int num) { trainNumber = num; }
    void setTrainName(const char* name) { strcpy(trainName, name); }
    void setSource(const char* src) { strcpy(source, src); }
    void setDestination(const char* dest) { strcpy(destination, dest); }
    void setTrainTime(const char* time) { strcpy(trainTime, time); }

    int getTrainNumber() const { return trainNumber; }
    const char* getTrainName() const { return trainName; }
    const char* getSource() const { return source; }
    const char* getDestination() const { return destination; }
    const char* getTrainTime() const { return trainTime; }

    void inputTrain() {
        char temp[50];
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore();
        cout << "Enter Train Name: ";
        cin.getline(temp, 50);
        setTrainName(temp);
        cout << "Enter Source: ";
        cin.getline(temp, 50);
        setSource(temp);
        cout << "Enter Destination: ";
        cin.getline(temp, 50);
        setDestination(temp);
        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrain() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
    }

    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() {
        totalTrains = 0;
    }

    void addTrain() {
        if (totalTrains < 100) {
            trains[totalTrains].inputTrain();
            totalTrains++;
            cout << "Train record added successfully.\n";
        } else {
            cout << "Cannot add more trains. Maximum limit reached.\n";
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records available.\n";
            return;
        }
        for (int i = 0; i < totalTrains; i++) {
            cout << "\n--- Train " << i + 1 << " Details ---\n";
            trains[i].displayTrain();
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                cout << "Train found:\n";
                trains[i].displayTrain();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found.\n";
        }
    }
};

int main() {
    RailwaySystem system;
    int choice;

    do {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3: {
            int searchNumber;
            cout << "Enter Train Number to search: ";
            cin >> searchNumber;
            system.searchTrainByNumber(searchNumber);
            break;
        }
        case 4:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
/*output
--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 1
Enter Train Number: 101
Enter Train Name: okha express
Enter Source: surat
Enter Destination: mumbai
Enter Train Time: 7 pm
Train record added successfully.

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 2

--- Train 1 Details ---
Train Number: 101
Train Name: okha express
Source: surat
Destination: mumbai
Train Time: 7 pm

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 3
Enter Train Number to search: 101
Train found:
Train Number: 101
Train Name: okha express
Source: surat
Destination: mumbai
Train Time: 7 pm

--- Railway Reservation System Menu ---
1. Add New Train Record
2. Display All Train Records
3. Search Train by Number
4. Exit
Enter your choice: 4
Exiting the system. Goodbye!
*/
