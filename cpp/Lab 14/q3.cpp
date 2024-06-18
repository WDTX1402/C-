#include <iostream>
#include <limits>

using namespace std;

class Point {
private:
    int xCoordinate;
    int yCoordinate;

public:
    Point() : xCoordinate(0), yCoordinate(0) {}

    friend istream &operator>>(istream &input,  Point &p) {
        input >> p.xCoordinate >> p.yCoordinate;
        if (!input) {
            input.clear(ios_base::failbit);
        }
        return input;
    }

    friend ostream &operator<<(ostream &output, const Point &p) {
        if (output.good()) {
            output << "(" << p.xCoordinate << ", " << p.yCoordinate << ")";
        }
        return output;
    }

};







int main() {
    Point point;

    cout << "Enter the x and y coordinates of a point (e.g., 10 20): ";
    while (cin >> point) {
        cout << "You entered the point: " << point << endl;
        cout << "\nEnter another point, or enter an invalid input to quit: ";
    }


    if (!cin.good()) {
        cout << "Input error: Invalid coordinates entered." << endl;
    }

    return 0;
}
