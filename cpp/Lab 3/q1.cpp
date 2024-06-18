#include <iostream>
#include <cstdint>
#include <string>

using namespace std;


class Conversion {
private:
    string choice;

public:
    Conversion() : choice("null") {} 

    void setChoice(string choicee) {
        choice = choicee;
    }

    string calculateTemperature(int tempInput) {
        if (choice == "c" || choice == "C") {
            double output;
            output = ((tempInput - 32) * 5) / 9;
            return to_string(tempInput) + " Fahrenheit is " + to_string(output) + " Celcius";
        } else if (choice == "f" || choice == "F") {
            double output;
            output = (tempInput * 9) / 5 + 32;
            return to_string(tempInput) + " Celcius is " + to_string(output) + " Fahrenheit";
        } else {
            return "No input";
        }
    }
};


int main() {
    Conversion tempconvert;
    while (true) {
        double tempInput;
        string choice;
        string continueornot;
        try {
            cout << "Please enter the temperature: ";
            if (!(cin >> tempInput)) {
                throw invalid_argument("Input was not a valid number.");
            }
            
            cout << "Convert to (C)elsius or (F)ahrenheit? Enter C or F: ";
            cin >> choice;
            if (choice != "C" && choice != "c" && choice != "F" && choice != "f") {
                throw invalid_argument("Choice must be C or F.");
            }

            tempconvert.setChoice(choice);
            cout << tempconvert.calculateTemperature(static_cast<int>(tempInput)) << endl;
            
            cout << "Do you want to perform another conversion (Y/N): ";
            cin >> continueornot;
            if (continueornot != "Y" && continueornot != "y" && continueornot != "N" && continueornot != "n") {
                throw invalid_argument("You must enter Y or N.");
            }

            if (continueornot == "n" || continueornot == "N") {
                break;
            }
            cin.clear();

        } catch (const invalid_argument& e) {
     
            cerr << "Error: " << e.what() << endl;

            cin.clear();
          

            cout << "Would you like to try again (Y/N)? ";
            cin >> continueornot;
            if (continueornot != "Y" && continueornot != "y") {
                break;
            }
        }
    }
    return 0;
}