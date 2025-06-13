#include <iostream>
using namespace std;

class MathOperations {
	
	public:
		double result;

    double divide(double numerator, double denominator) {
        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed!");
        }
        return numerator / denominator;
    }
};

int main() {
    MathOperations math;
    double a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try {
        double result = math.divide(a, b);
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

}
/*output
Enter numerator: 12
Enter denominator: 324
Result: 0.037037
*/
