#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string ownerName;
    string accountNumber;
    double balance;

public:
  
    BankAccount(string owner, string accNo, double bal) {
        ownerName = owner;
        accountNumber = accNo;
        balance = bal;
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        cout << "Owner Name   : " << ownerName << endl;
        cout << "Account No.  : " << accountNumber << endl;
        cout << "Balance      : ?" << balance << endl;
        }
    void operator+(const BankAccount& other) const {
        cout << "\n[Combined Account Balance Details]" << endl;
        cout << "Account 1: ?" << this->balance << endl;
        cout << "Account 2: ?" << other.balance << endl;
        cout << "Total Balance: ?" << (this->balance + other.balance) << endl;
    }
};

int main() {
  
    BankAccount acc1("Janvi Ghava", "11110001", 8500.50);
    BankAccount acc2("Riya Patel", "11110002", 9200.75);

    cout << "--- Account 1 ---" << endl;
    acc1.display();

    cout << "\n--- Account 2 ---" << endl;
    acc2.display();

    acc1 + acc2;

}
/*output
--- Account 1 ---
Owner Name   : Janvi Ghava
Account No.  : 11110001
Balance      : 8500.5

--- Account 2 ---
Owner Name   : Riya Patel
Account No.  : 11110002
Balance      : 9200.75

[Combined Account Balance Details]
Account 1: 8500.5
Account 2: 9200.75
Total Balance: 17701.2
*/
