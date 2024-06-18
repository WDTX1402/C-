#include <iostream>
#include <string>

using namespace std;

class HeartRateMonitor {
private:
    string firstName;
    string lastName;
    int b_year;
    int b_month;
    int b_day;
    int age;
    int max_rate;
    double min_tager_rate;
    double max_tager_rate;

public:
    HeartRateMonitor(const string& firstName, const string& lastName, 
                     int b_year, int b_month, int b_day) :
                     firstName(firstName), lastName(lastName), 
                     b_year(b_year), b_month(b_month), b_day(b_day) {
        
 
        int const currentYear = 2023;
        int const currentMonth = 12;
        int const currentDay = 28;

      
        age = currentYear - b_year;
        if (b_month > currentMonth || (b_month == currentMonth && b_day > currentDay)) {
            age--; 
        }

        max_rate = 220 - age;
        min_tager_rate = max_rate * 0.50;
        max_tager_rate = max_rate * 0.85;
    }


    void displayInformation() {
        cout << "Hello, " << age << " years old " << firstName << " " << lastName << ".\n";
        cout << "Your maximum heart rate should be " << max_rate << " beats per minute.\n";
        cout << "Your target heart rate range is " << min_tager_rate << " – " 
                  << max_tager_rate << " beats per minute.\n";
    }
};

int main() {
    string firstName;
    string lastName;
    int b_year;
    int b_month;
    int b_day;

    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cout << "Enter your birth year (YYYY): ";
    cin >> b_year;

    cout << "Enter your birth month (MM): ";
    cin >> b_month;

    cout << "Enter your birth day (DD): ";
    cin >> b_day;

    
    HeartRateMonitor monitor(firstName, lastName, b_year, b_month, b_day);

    monitor.displayInformation();

    return 0;
}
