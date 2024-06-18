#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {}

    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == denominator * other.numerator;
    }

    bool operator>(const Fraction& other) const {
        double value1 = static_cast<double>(numerator) / denominator;
        double value2 = static_cast<double>(other.numerator) / other.denominator;
        return value1 > value2;
    }

    bool operator<(const Fraction& other) const {
        double value1 = static_cast<double>(numerator) / denominator;
        double value2 = static_cast<double>(other.numerator) / other.denominator;
        return value1 < value2;
    }

    Fraction operator+(const Fraction& other) const {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        int gcd = std::gcd(new_numerator, new_denominator);

        return Fraction(new_numerator / gcd, new_denominator / gcd);
    }

    Fraction operator-(const Fraction& other) const {
        int new_numerator = numerator * other.denominator - other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        int gcd = std::gcd(new_numerator, new_denominator);

        return Fraction(new_numerator / gcd, new_denominator / gcd);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        int gcd = std::gcd(num, denom);

        return Fraction(num / gcd, denom / gcd);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        int gcd = std::gcd(num, denom);

        return Fraction(num / gcd, denom / gcd);
    }
    
    friend std::istream& operator>>(std::istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        if(f.numerator == 0) {
            os << "0";
        } else {
            os << f.numerator << "/" << f.denominator;
        }
        return os;
    }
};

int main() {
    Fraction f1, f2;
    std::cout << "Enter first fraction (format a/b): ";
    std::cin >> f1;
    std::cout << "Enter second fraction (format a/b): ";
    std::cin >> f2;
    if(f1.denominator != 0 && f2.denominator != 0) {
        std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;
        std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;
        std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;
        std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;

        if (f1 == f2) std::cout << "f1 is equal to f2" << std::endl;
        if (f1 > f2) std::cout << "f1 is greater than f2" << std::endl;
        if (f1 < f2) std::cout << "f1 is less than f2" << std::endl;
    } else {
        cout << "Denominator cannot be 0\n";
    }

    return 0;
}