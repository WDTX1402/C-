// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// class PopulationGrowth {
//     private:
//         vector<int> pop_results;
//         vector<int> pop_difference;
    
//     public:   
//         tuple<vector<int>,vector<int>> get_pop_results (int initial_input,double growth_rate) {
//             int i = 1;
//             int initial_pop = initial_input;
//             while (i <= 75) {
//                 int next_year = initial_pop * growth_rate;
//                 pop_results.push_back(next_year);

//                 int increased = next_year - initial_pop;
//                 pop_difference.push_back(increased);

//                 initial_pop = next_year;
//                 i++;
//             }
//             return make_tuple(pop_results,pop_results);
//         }

// };

// int main() {
//     PopulationGrowth pop_growth;
//     int pop;
//     double growth;
//     cout << "Enter the current world population: ";
//     cin >> pop;
//     cout << "Enter the annual growth rate (percentage): ";
//     cin >> growth;

//     tuple<vector<int>,vector<int>> result = pop_growth.get_pop_results(pop,growth);
//     vector<int> result1 = get<0>(result);
//     vector<int> result2 = get<1>(result);

//     int i = 1;
//     int idx = 0;
//     cout << "Year\tProjected Population\tAnnual Increase" << endl;
//     while (i <= 75) {
//         cout << i + "\t";
//         cout << result1[i];
//         cout << "\t";
//         cout << result2[i] << endl;
//         i++;
//         idx++;
//     }
    

// }

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>

using namespace std;

class PopulationGrowth {
private:
    vector<int> pop_results;        
    vector<int> pop_difference;     

public:   
    tuple<vector<int>, vector<int>> get_pop_results(int initial_input, double growth_rate) {
        int i = 1;
        int initial_pop = initial_input;
        growth_rate /= 100.0; 
        while (i <= 75) {
            int next_year = initial_pop + (initial_pop * growth_rate);
            pop_results.push_back(next_year);

            int increased = next_year - initial_pop;
            pop_difference.push_back(increased);

            initial_pop = next_year;
            i++;
        }
        return make_tuple(pop_results, pop_difference);
    }
};
string formatWithCommas(int number) {
        string formatted = to_string(number);
        int len = formatted.length();
        for (int i = len - 3; i > 0; i -= 3) {
            formatted.insert(i, ",");
        }
        return formatted;
    }


#include <iostream>
#include <iomanip>  // For std::setw
#include <tuple>    // Assuming you use std::tuple in PopulationGrowth

using namespace std;

// Assuming the PopulationGrowth class and formatWithCommas function are defined elsewhere

int main() {
    PopulationGrowth pop_growth;
    int pop;      
    double growth;      
    cout << "Enter the current world population: ";
    cin >> pop;
    cout << "Enter the annual growth rate (percentage): ";
    cin >> growth;

    auto result = pop_growth.get_pop_results(pop, growth);
    auto& result1 = get<0>(result);
    auto& result2 = get<1>(result);
    bool check = false;

    // Assuming you want a specific width for each column. Adjust these as needed.
    int yearWidth = 10;
    int popWidth = 25;
    int increaseWidth = 25;

    cout << left << setw(yearWidth) << "Year" << setw(popWidth) << "Projected Population" << setw(increaseWidth) << "Annual Increase" << endl;

    for (int i = 0; i < 75; ++i) {
        cout << setw(yearWidth) << (i + 1);
        cout << setw(popWidth) << formatWithCommas(result1[i]);
        if (pop * 2 <= result1[i] && !check) {
            cout << setw(increaseWidth) << formatWithCommas(result2[i]) << "<Population doubled here" << endl;
            check = true;
        } else {
            cout << setw(increaseWidth) << formatWithCommas(result2[i]) << endl;
        }
    }
}
