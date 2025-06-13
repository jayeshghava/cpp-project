#include <iostream>
using namespace std;


class Shape {
public:
   
    virtual void calculateArea() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    void getInput() {
        cout << "Enter radius of circle: ";
        cin >> radius;
    }

    void calculateArea() override {
        float area = 3.14 * radius * radius;
        cout << "Circle Area: " << area << endl;
    }

    void draw() override {
        cout << "Drawing Circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    float length, width;

public:
    void getInput() {
        cout << "Enter length and width of rectangle: ";
        cin >> length >> width;
    }

    void calculateArea() override {
        float area = length * width;
        cout << "Rectangle Area: " << area << endl;
    }

    void draw() override {
        cout << "Drawing Rectangle of size " << length << " x " << width << endl;
    }
};

int main() {
   
    Circle c;
    Rectangle r;

    cout << "--- Circle Input ---" << endl;
    c.getInput();

    cout << "--- Rectangle Input ---" << endl;
    r.getInput();

    Shape* shapes[2];
    shapes[0] = &c;
    shapes[1] = &r;

    cout << "--- Output ---" << endl;
    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        shapes[i]->calculateArea();
        cout << "------------------------" << endl;
    }

}
/*output
--- Circle Input ---
Enter radius of circle: 12
--- Rectangle Input ---
Enter length and width of rectangle: 2
78
--- Output ---
Drawing Circle with radius 12
Circle Area: 452.16
------------------------
Drawing Rectangle of size 2 x 78
Rectangle Area: 156
------------------------
*/
