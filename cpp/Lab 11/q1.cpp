// #include <string>
// #include <vector>s
// #include <fstream>
// #include <iostream>

// using namespace std;

// struct Movie{
//     string title;
//     string date;
//     vector<vector<bool>> available_seat;

// };

// struct Reservation{
//     string customerName;
//     string movieTitle;
//     string date;
//     int round;
//     int seatNumber;
// };


// void displaySchedule(vector<Movie> movies){
//     for( int i = 0; i < movies.size(); i++){
//         cout <<" Title: "<< movies[i].title << endl;
//         cout <<" Date: "<< movies[i].date << endl;
//         cout <<" Seat(s) available: "<< movies[i].date << endl;
//     }
// }

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

    
struct Movie {
    string title;
    vector<string> date;
    vector<string> round;
    vector<vector<int>> available_seats;
    
};

struct Reservation{
    string customerName;
    int numberOfSeats;;

};


void displaySchedule(const vector<Movie>& movies) {
    for (const auto& movie : movies) {
        cout << "Movie: " << movie.title << endl;
        for (int day = 0; day < movie.date.size(); ++day) {
            cout << "Date: " << movie.date[day] << endl;
            for (int rnd = 0; rnd < movie.round.size(); rnd++) {
                    cout << "Round " << movie.round[rnd] << ": " << movie.available_seats[day][rnd] << " seats available." << endl;
            }
            cout  << endl;
        }
        cout << "\n" << endl;
    }
}


void makeReservation(vector<Movie>& movies, string movieTitle, string movieDate, string selectedRound, int reserve_num) {

    for (auto& movie : movies) {
        if (movie.title == movieTitle) {
            int dateIDX = -1;
            for (int i = 0; i < movie.date.size(); ++i) {
                if (movie.date[i] == movieDate) {
                    dateIDX = i;
                    break;
                }
            }

            int roundIDX = -1;
            for (int i = 0; i < movie.round.size(); ++i) {
                if (movie.round[i] == selectedRound) {
                    roundIDX = i;
                    break;
                }
            }

            if (dateIDX != -1 && roundIDX != -1) {
                if (movie.available_seats[dateIDX][roundIDX] >= reserve_num) {
                    movie.available_seats[dateIDX][roundIDX] -= reserve_num;
                    cout << "Successfully reserved " << reserve_num << " seats for " << movieTitle << " on " << movieDate << " for round " << selectedRound << "." << endl;
                    return;
                } else {
                    cout << "Not enough seats available, Maximum seats available is: "<< movie.available_seats[dateIDX][roundIDX] << endl;
                    return;
                }
            } else {
                if (dateIDX == -1) cout << "Date not found." << endl;
                if (roundIDX == -1) cout << "Round not found." << endl;
                return;
            }
        }
    }
    cout << "Movie not found." << endl;
}

// void cancelReservation()
int main() {
    vector<Movie> movies = {
        {"Poor Things", 
         {"2024-03-01", "2024-03-02", "2024-03-03"}, 
         {"12:10", "13:10", "15:00", "21:10"}, 
         {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}
        }, 
         
        {"เหมรย", 
         {"2024-03-01", "2024-03-02", "2024-03-03"}, 
         {"12:10", "13:10", "14:10", "21:10"}, 
         {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}},

        {"4KingsII", 
         {"2024-03-01", "2024-03-02", "2024-03-03"}, 
         {"12:10", "13:10", "14:10", "21:10"}, 
         {{10, 10, 10, 10}, {10, 10, 10, 10}, {10, 10, 10, 10}}}
    };

    int choice;
    do {
        cout << "1. View Schedule\n2. Make Reservation\n3. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                displaySchedule(movies);
                break;
            case 2: {
                string movieTitle, movieDate, selectedRound;
                int reserve_num;
                for (int i = 0 ; i < movies.size(); i++) {
                        cout << i + 1<< ".) Movie: " << movies[i].title << endl;
                }
                cout << "Choose a movie: ";
                cin.ignore(); 
                int select_movie;
                cin >> select_movie; 
                movieTitle = movies[select_movie- 1].title;
    
                for (int j = 0 ; j < movies[select_movie-1].date.size(); j++){
                        cout << j + 1<< ".) Date: " << movies[select_movie-1].date[j] << endl;
                }
                cout << "Choose a date: ";
                cin.ignore(); 
                int select_date;
                cin >> select_date;
                movieDate= movies[select_movie- 1].date[select_date-1]; 
        
                cout << "Enter round (HH:MM): ";
                cin >> selectedRound;
                cout << "Enter number of seats to reserve: ";
                cin >> reserve_num;

                makeReservation(movies, movieTitle, movieDate, selectedRound, reserve_num);
                break;
            }
            case 3:
                cout << "Good Bye\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 3);

    return 0;
}