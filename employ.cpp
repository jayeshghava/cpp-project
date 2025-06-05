#include <iostream>
#include <string.h>
using namespace std;


class Employee {
public:
   
    int emp_id;
    string emp_name;
    int emp_age;
    string emp_role;
    double emp_salary;
    string emp_city;
    int emp_experience;
    string emp_company_name;

   
    void inputDetails() {
        cout << "Enter Employee ID: ";
        cin >> emp_id;
        cin.ignore(); 
        cout << "Enter Employee Name: ";
        getline(cin, emp_name);
        cout << "Enter Employee Age: ";
        cin >> emp_age;
        cin.ignore();
        cout << "Enter Employee Role: ";
        getline(cin, emp_role);
        cout << "Enter Employee Salary: ";
        cin >> emp_salary;
        cin.ignore();
        cout << "Enter Employee City: ";
        getline(cin, emp_city);
        cout << "Enter Employee Experience (years): ";
        cin >> emp_experience;
        cin.ignore();
        cout << "Enter Employee Company Name: ";
        getline(cin, emp_company_name);
        cout << "---------------------------------\n";
    }

    
    void displayDetails() {
        cout << "Employee ID: " << emp_id << endl;
        cout << "Name: " << emp_name << endl;
        cout << "Age: " << emp_age << endl;
        cout << "Role: " << emp_role << endl;
        cout << "Salary: $" << emp_salary << endl;
        cout << "City: " << emp_city << endl;
        cout << "Experience: " << emp_experience << " years" << endl;
        cout << "Company: " << emp_company_name << endl;
        cout << "---------------------------------\n";
    }
};

int main() {
    const int EMP_COUNT = 5;
    Employee employees[EMP_COUNT];

    cout << "=== Enter Details for 5 Employees ===\n";
    for (int i = 0; i < EMP_COUNT; i++) {
        cout << "\nEntering details for Employee " << i + 1 << ":\n";
        employees[i].inputDetails();
    }

    cout << "\n=== Displaying Employee Records ===\n";
    for (int i = 0; i < EMP_COUNT; i++) {
        cout << "\nEmployee " << i + 1 << " Details:\n";
        employees[i].displayDetails();

    }

  
}
/*output

=== Enter Details for 5 Employees ===

Entering details for Employee 1:
Enter Employee ID: 51209
Enter Employee Name: natavarlal
Enter Employee Age: 56
Enter Employee Role: management
Enter Employee Salary: 5600
Enter Employee City: junaghdh
Enter Employee Experience (years): 14
Enter Employee Company Name: varsha industris private limitade
---------------------------------

Entering details for Employee 2:
Enter Employee ID: 51210
Enter Employee Name: bagheshvar
Enter Employee Age: 34
Enter Employee Role: consulting
Enter Employee Salary: 67000
Enter Employee City: rajkot
Enter Employee Experience (years): 12
Enter Employee Company Name: jalaram group of companies
---------------------------------

Entering details for Employee 3:
Enter Employee ID: 51211
Enter Employee Name: manoj rathod
Enter Employee Age: 55
Enter Employee Role: administrive mini8ster
Enter Employee Salary: 78000
Enter Employee City: jamnagar
Enter Employee Experience (years): 34
Enter Employee Company Name: reliance
---------------------------------

Entering details for Employee 4:
Enter Employee ID: 51212
Enter Employee Name: ashish kumar
Enter Employee Age: 25
Enter Employee Role: bill collecter
Enter Employee Salary: 31000
Enter Employee City: earth expo company
Enter Employee Experience (years): 23
Enter Employee Company Name: earth expo company in  bhavnagar
---------------------------------

Entering details for Employee 5:
Enter Employee ID: 51213
Enter Employee Name: abhimanyu birlla
Enter Employee Age: 29
Enter Employee Role: support agent.
Enter Employee Salary: 890000
Enter Employee City: bengalore
Enter Employee Experience (years): 14
Enter Employee Company Name: finolex industries
---------------------------------

=== Displaying Employee Records ===

Employee 1 Details:
Employee ID: 51209
Name: natavarlal
Age: 56
Role: management
Salary: $5600
City: junaghdh
Experience: 14 years
Company: varsha industris private limitade
---------------------------------

Employee 2 Details:
Employee ID: 51210
Name: bagheshvar
Age: 34
Role: consulting
Salary: $67000
City: rajkot
Experience: 12 years
Company: jalaram group of companies
---------------------------------

Employee 3 Details:
Employee ID: 51211
Name: manoj rathod
Age: 55
Role: administrive mini8ster
Salary: $78000
City: jamnagar
Experience: 34 years
Company: reliance
---------------------------------

Employee 4 Details:
Employee ID: 51212
Name: ashish kumar
Age: 25
Role: bill collecter
Salary: $31000
City: earth expo company
Experience: 23 years
Company: earth expo company in  bhavnagar
---------------------------------

Employee 5 Details:
Employee ID: 51213
Name: abhimanyu birlla
Age: 29
Role: support agent.
Salary: $890000
City: bengalore
Experience: 14 years
Company: finolex industries
-
*/
