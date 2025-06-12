#include <iostream>
#include <string>
using namespace std;

class VotingException : public exception {
public:
    const char* what() const noexcept override {
        return "You must be at least 18 years old to vote.";
    }
};
class PasswordException : public exception {
public:
    const char* what() const noexcept override {
        return "Password must contain at least one uppercase letter.";
    }
};
void divideNumbers(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed.");
    }
    cout << "Result of division: " << a / b << endl;
}
void checkVotingEligibility(int age) {
    if (age < 18) {
        throw VotingException();
    }
    cout << "You are eligible to vote." << endl;
}
void validatePassword(const string& password) {
    bool hasUpper = false;
    for (char ch : password) {
        if (isupper(ch)) {
            hasUpper = true;
            break;
        }
    }
    if (!hasUpper) {
        throw PasswordException();
    }
    cout << "Password is valid." << endl;
}

int main() {
     try {
        int num1, num2;
        cout << "Enter two numbers (dividend and divisor): ";
        cin >> num1 >> num2;
        divideNumbers(num1, num2);
    } catch (const exception& e) {
        cout << "Exception caught (Division): " << e.what() << endl;
    }
    try {
        int age;
        cout << "\nEnter your age: ";
        cin >> age;
        checkVotingEligibility(age);
    } catch (const exception& e) {
        cout << "Exception caught (Voting): " << e.what() << endl;
    }
    try {
        string password;
        cout << "\nEnter your password: ";
        cin >> password;
        validatePassword(password);
    } catch (const exception& e) {
        cout << "Exception caught (Password): " << e.what() << endl;
    }
}