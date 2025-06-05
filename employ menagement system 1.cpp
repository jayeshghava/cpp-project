#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employee_id;
    string name;
    int age;
    float salary;

public:
    Employee() {}

    Employee(int id, string n, int a, float s) {
        employee_id = id;
        name = n;
        age = a;
        salary = s;
    }

    virtual void display() {
        cout << "ID: " << employee_id
             << ", Name: " << name
             << ", Age: " << age
             << ", Salary: " << salary;
    }

    int getId() {
        return employee_id;
    }
    virtual ~Employee() {

    }
};

class FullTimeEmployee : public Employee {
    float bonus;

public:
    FullTimeEmployee(int id, string n, int a, float s, float b)
        : Employee(id, n, a, s) {
        bonus = b;
    }

    void display() override {
        Employee::display();
        cout << ", Bonus: " << bonus << " [Full-Time]" << endl;
    }

    ~FullTimeEmployee() {
        cout << "Deleting Full-Time Employee ID: " << employee_id << endl;
    }
};

class PartTimeEmployee : public Employee {
    int hours_worked;

public:
    PartTimeEmployee(int id, string n, int a, float s, int h)
        : Employee(id, n, a, s) {
        hours_worked = h;
    }

    void display() override {
        Employee::display();
        cout << ", Hours Worked: " << hours_worked << " [Part-Time]" << endl;
    }

    ~PartTimeEmployee() {
        cout << "Deleting Part-Time Employee ID: " << employee_id << endl;
    }
};

int main() {
    const int MAX = 100;
    Employee* employees[MAX] = {nullptr};
    int count = 0;

    int choice;

    do {
        cout << "\n======= Employee Management System =======\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Delete Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int type;
            cout << "1. Full-Time Employee\n2. Part-Time Employee\nEnter type: ";
            cin >> type;

            int id, age, hours;
            float salary, bonus;
            string name;

            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Salary: ";
            cin >> salary;

            if (type == 1) {
                cout << "Enter Bonus: ";
                cin >> bonus;
                employees[count++] = new FullTimeEmployee(id, name, age, salary, bonus);
            } else if (type == 2) {
                cout << "Enter Hours Worked: ";
                cin >> hours;
                employees[count++] = new PartTimeEmployee(id, name, age, salary, hours);
            } else {
                cout << "Invalid employee type!\n";
            }
            break;
        }
        case 2: {
            cout << "\n--- Employee List ---\n";
            for (int i = 0; i < count; i++) {
                if (employees[i]) {
                    employees[i]->display();
                }
            }
            break;
        }

        case 3: {
            int del_id;
            cout << "Enter Employee ID to delete: ";
            cin >> del_id;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (employees[i] && employees[i]->getId() == del_id) {
                    delete employees[i];
                    employees[i] = nullptr;
                    found = true;
                    cout << "Employee deleted.\n";
                    break;
                }
            }
            if (!found) {
                cout << "Employee ID not found.\n";
            }
            break;
        }
        case 4: {

            for (int i = 0; i < count; i++) {
                if (employees[i]) {
                    delete employees[i];
                    employees[i] = nullptr;
                }
            }
            cout << "Exiting program. Memory cleaned.\n";
            break;
        }
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

}
