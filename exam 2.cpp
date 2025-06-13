#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
  
    BankAccount(string accNum, string owner, double initialBalance) {
        accountNumber = accNum;
        ownerName = owner;
        balance = initialBalance;
    }

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Credited: ?" << amount << endl;
        } else {
            cout << "Invalid amount. Cannot credit." << endl;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Debited: ?" << amount << endl;
        } else {
            cout << "Invalid amount or insufficient balance." << endl;
        }
    }
    void display() const {
        cout << "\nAccount Holder: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: ?" << balance << endl;
    }
};

int main() {

    BankAccount account("1234567890", "Janvi Ghava", 5000.0);

    account.display();

    account.credit(1500.0);
    account.debit(2000.0);
    account.debit(6000.0); 

    account.display(); 

}
/*output
Account Holder: Janvi Ghava
Account Number: 1234567890
Current Balance: 5000
Credited: 1500
Debited: 2000
Invalid amount or insufficient balance.

Account Holder: Janvi Ghava
Account Number: 1234567890
Current Balance: 4500
*/
