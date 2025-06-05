#include <iostream>
using namespace std;

class A {
protected:
    int num1;
public:
    A(int a) {
        num1 = a;
    }
};

class B : virtual public A {
protected:
    int num2;
public:
    B(int a, int b) : A(a) {
        num2 = b;
    }
};

class C : virtual public A {
protected:
    int num3;
public:
    C(int a, int c) : A(a) {
        num3 = c;
    }
};

class D : public B, public C {
    int num4;
public:
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c) {
        num4 = d;
    }

    void displaySum() {
        int sum = num1 + num2 + num3 + num4;
        cout << "Sum of four numbers: " << sum << endl;
    }
};

int main() {
    int a, b, c, d;
    cout << "Enter four numbers: ";
    cin >> a >> b >> c >> d;

    D obj(a, b, c, d);
    obj.displaySum();

}
/*output
Enter four numbers: 435
453
546
4657
Sum of four numbers: 6091
*/
