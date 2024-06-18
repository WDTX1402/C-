#include <iostream>
#include <string>

using namespace std;

class Temperature
{
public:
    double fahr_to_cel(double f)
    {
        return (f - 32) * 5 / 9;
    }
    double cel_to_fahr(double c)
    {
        return c * 9 / 5 + 32;;
    }
};

int main() {
    Temperature convert;

    while (true) {
        cout << "Enter Temperature: ";
        double x;
        cin >> x;

        cout << "Convert to (C)elsius or (F)ahrenheit? Enter C or F: ";
        char choice;
        cin >> choice;

        if (choice == 'f' || choice == 'F') {
            cout << x << " Celsius is " << convert.cel_to_fahr(x) << " Fahrenheit" << endl;
        } else if (choice == 'c' || choice == 'C') {
            cout << x << " Fahrenheit is " << convert.fahr_to_cel(x) << " Celsius" << endl;
        }
        cin.clear();
        cout << "Do you want to continue? (Y/N): ";
        string decision;
        getline(cin, decision);

        if (decision == "n" || decision == "N") {
            break;
        }
    }

    return 0;
}