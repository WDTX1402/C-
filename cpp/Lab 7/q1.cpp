#include <string>
#include <vector>
#include <iostream>
#include <array>
#include <iomanip>

using namespace std;


const int ROW = 5;
const int COLUMN = 10;

class Food_lol {
    private:
        array<string, 5> dishes = {"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};
        array<array<int, COLUMN>, ROW> responses = {}; // ROW dishes, each with COLUMN possible scores


    public:
        void collect_ratings(int row, int score) {
            if (score >= 1 && score <= 10) {
                responses[row][score]++; 
            }
        }

        string display_foods(int row) {
            return dishes[row];
        }

        int display_ratings(int row, int column) {
            return responses[row][column];
        }
};




int main() {
    Food_lol poll;

    for (int pollNumber = 0; pollNumber < 5; ++pollNumber) {
        cout << "Poll " << pollNumber + 1 << endl;

  
        for (int dishIndex = 0; dishIndex < ROW; ++dishIndex) {
            int score;
            cout << "Rate " << poll.display_foods(dishIndex) << " on a scale of 1 to 10: ";
            while (true) {
                cin >> score;
                if (score >= 1 && score <= 10) {
                    poll.collect_ratings(dishIndex, score - 1); 
                    break;
                } else {
                    cout << "Invalid score. Please enter a number between 1 and 10: ";
                }
            }
        }
        cout << endl;
    }


    cout << "Survey results" << endl;
    cout << left << setw(20) << "Dish" << "\t";
    int i = 1;
    while (i <= COLUMN) {
        cout << i << "\t";
        i++;
    }
    cout << "Average" << endl;

    for (int k = 0; k < ROW; k++) {
        cout << left << setw(20) << poll.display_foods(k) << "\t";
        int total = 0, count = 0;
        for (int j = 0; j < COLUMN; j++) {
            int ratingCount = poll.display_ratings(k, j);
            cout << ratingCount << "\t";
            total += ratingCount * (j + 1);
            count += ratingCount; 
        }

        double avg = count > 0 ? static_cast<double>(total) / count : 0;
        cout << fixed << setprecision(1) << avg << endl; 
    }

    int highscore = 0;
    int lowscore = INT_MAX; 
    string highest;
    string lowest;

    for (int k = 0; k < ROW; k++) {
        int total = 0;
        for (int j = 0; j < COLUMN; j++) {
            total += poll.display_ratings(k, j) * (j + 1);
        }

        if (total > highscore) {
            highscore = total;
            highest = poll.display_foods(k);
        }

        if (total < lowscore) {
            lowscore = total;
            lowest = poll.display_foods(k);
        }
    }

    cout << "Highest Rated Dish: " << highest << " (Score: " << highscore << ")" << endl;
    cout << "Lowest Rated Dish: " << lowest << " (Score: " << lowscore << ")" << endl;
    return 0;
}
