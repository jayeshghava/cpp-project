#include <iostream>
using namespace std;

int main()
{
    int num1[] = { 12,42,15,55,26 };
    int n = 5;
    for (int i = 0; i < n; i++) {
        if (num1[i] %2!= 0) {
            cout << num1[i] << " ";
        }
    }

    
}
/*output
12 42 26
*/