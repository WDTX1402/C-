#include <iostream>
#include <numeric> 

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    
public:

    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        if (d == 0) {
            throw runtime_error("Denominator cannot be zero.");
        }
        reduce();
    }

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    friend istream& operator>>(istream& in, Fraction& f) {
        char slash;
        in >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw runtime_error("Invalid fraction. Denominator cannot be zero.");
        }
        f.reduce();
        return in;
    }


    friend ostream& operator<<(ostream& out, const Fraction& f) {
        out << f.numerator << '/' << f.denominator;
        return out;
    }


    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }
};

int main() {
    Fraction f1, f2;

    try {
        cout << "Enter first fraction (format a/b): ";
        cin >> f1;
        cout << "Enter second fraction (format a/b): ";
        cin >> f2;

        cout << "f1 + f2 = " << (f1 + f2) << endl;
        cout << "f1 - f2 = " << (f1 - f2) << endl;
        cout << "f1 * f2 = " << (f1 * f2) << endl;
        cout << "f1 / f2 = " << (f1 / f2) << endl;

        if (f1 == f2) cout << "f1 is equal to f2" << endl;
        if (f1 != f2) cout << "f1 is not equal to f2" << endl;
        if (f1 > f2) cout << "f1 is greater than f2" << endl;
        if (f1 < f2) cout << "f1 is less than f2" << endl;
        if (f1 >= f2) cout << "f1 is greater than or equal to f2" << endl;
        if (f1 <= f2) cout << "f1 is less than or equal to f2" << endl;
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
