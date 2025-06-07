#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
private:
    double balance;
public:
    BankAccount(string accNo, string accHolder, double initialBalance)
        : accountNumber(accNo), accountHolderName(accHolder), balance(initialBalance) {}

    virtual ~BankAccount() {}
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited successfully.\n";
        }
    }
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
    double getBalance() const {
        return balance;
    }
    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
    virtual void calculateInterest() const = 0; 
};
class SavingsAccount : public BankAccount {
private:
    double interestRate;
public:
    SavingsAccount(string accNo, string accHolder, double initialBalance, double rate)
        : BankAccount(accNo, accHolder, initialBalance), interestRate(rate) {}

    void calculateInterest() const override {
        double interest = getBalance() * interestRate / 100;
        cout << "Savings Interest: " << interest << endl;
    }
};
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNo, string accHolder, double initialBalance, double limit)
        : BankAccount(accNo, accHolder, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= getBalance() + overdraftLimit) {
            BankAccount::withdraw(amount);
        } else {
            cout << "Withdrawal exceeds overdraft limit.\n";
        }
    }

    void checkOverdraft() const {
        cout << "Overdraft limit: " << overdraftLimit << endl;
    }

    void calculateInterest() const override {
        cout << "No interest for checking accounts.\n";
    }
};
class FixedDepositAccount : public BankAccount {
private:
    int term;  

public:
    FixedDepositAccount(string accNo, string accHolder, double initialBalance, int t)
        : BankAccount(accNo, accHolder, initialBalance), term(t) {}

    void calculateInterest() const override {
        double rate = 7.5;   
        double interest = getBalance() * rate / 100 * (term / 12.0);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << endl;
    }
};
void showMenu() {
    cout << "\n1. Create Savings Account";
    cout << "\n2. Create Checking Account";
    cout << "\n3. Create Fixed Deposit Account";
    cout << "\n4. Deposit";
    cout << "\n5. Withdraw";
    cout << "\n6. Display Account Info";
    cout << "\n7. Calculate Interest (Polymorphism)";
    cout << "\n8. Exit";
    cout << "\nEnter choice: ";
}

int main() {
    vector<shared_ptr<BankAccount>> accounts;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string accNo, name;
            double bal, rate;
            cout << "Enter Account Number, Holder Name, Balance, Interest Rate: ";
            cin >> accNo >> name >> bal >> rate;
            accounts.push_back(make_shared<SavingsAccount>(accNo, name, bal, rate));
            break;
        }
        case 2: {
            string accNo, name;
            double bal, limit;
            cout << "Enter Account Number, Holder Name, Balance, Overdraft Limit: ";
            cin >> accNo >> name >> bal >> limit;
            accounts.push_back(make_shared<CheckingAccount>(accNo, name, bal, limit));
            break;
        }
        case 3: {
            string accNo, name;
            double bal;
            int term;
            cout << "Enter Account Number, Holder Name, Balance, Term (months): ";
            cin >> accNo >> name >> bal >> term;
            accounts.push_back(make_shared<FixedDepositAccount>(accNo, name, bal, term));
            break;
        }
        case 4: {
            int index;
            double amount;
            cout << "Enter account index and amount to deposit: ";
            cin >> index >> amount;
            if (index >= 0 && index < accounts.size()) {
                accounts[index]->deposit(amount);
            }
            break;
        }
        case 5: {
            int index;
            double amount;
            cout << "Enter account index and amount to withdraw: ";
            cin >> index >> amount;
            if (index >= 0 && index < accounts.size()) {
                accounts[index]->withdraw(amount);
            }
            break;
        }
        case 6: {
            for (size_t i = 0; i < accounts.size(); i++) {
                cout << "\nAccount Index: " << i << endl;
                accounts[i]->displayAccountInfo();
            }
            break;
        }
        case 7: {
            for (auto& acc : accounts) {
                acc->calculateInterest();
            }
            break;
        }
        case 8:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);
}
/*output
1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest (Polymorphism)
8. Exit
Enter choice: 1
Enter Account Number, Holder Name, Balance, Interest Rate: 0122345
Mr.shah
5000000
5000

1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest (Polymorphism)
8. Exit
Enter choice: 5
Enter account index and amount to withdraw: 0122345
50000

1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest (Polymorphism)
8. Exit
Enter choice: 6

Account Index: 0
Account Number: 0122345
Account Holder: Mr.shah
Balance: 5e+06

1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest (Polymorphism)
8. Exit
Enter choice: 7
Savings Interest: 2.5e+08

1. Create Savings Account
2. Create Checking Account
3. Create Fixed Deposit Account
4. Deposit
5. Withdraw
6. Display Account Info
7. Calculate Interest (Polymorphism)
8. Exit
Enter choice: 8
Exiting program...
*/
