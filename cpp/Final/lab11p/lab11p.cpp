#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int NUM_TIMES = 4;
const int COLS = 10;

// Movie struct
struct Movie {
    string title;
    string date;
    vector<vector<bool>> availableSeats;
};

// Reservation struct
struct Reservation {
    string customerName;
    string movieTitle;
    string date;
    int timeSlot;
    int seatNumber;
};

// Function prototypes
void displaySchedule(const vector<Movie>& movies);
void makeReservation(vector<Movie>& movies);

int main() {
    vector<Movie> movies = {
        {"Poor Things", "2024-03-01", vector<vector<bool>>(NUM_TIMES, vector<bool>(COLS, true))},
        {"เหมรย", "2024-03-02", vector<vector<bool>>(NUM_TIMES, vector<bool>(COLS, true))},
        {"4KingsII", "2024-03-03", vector<vector<bool>>(NUM_TIMES, vector<bool>(COLS, true))}
    };

    int choice;
    do {
        cout << "\n1. View Schedule\n2. Make Reservation\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySchedule(movies);
                break;
            case 2:
                makeReservation(movies);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}

void displaySchedule(const vector<Movie>& movies) {
    for (const auto& movie : movies) {
        cout << "\nMovie: " << movie.title << endl;
        cout << "Date: " << movie.date << endl;
        for (int time = 0; time < NUM_TIMES; ++time) {
            int availableSeats = count(movie.availableSeats[time].begin(), movie.availableSeats[time].end(), true);
            cout << "  " << (time == 0 ? "12:00" : time == 1 ? "15:00" : time == 2 ? "18:00" : time == 3 ? "21:00" : "") << ": " << availableSeats << " seats available" << endl;
        }
    }
} 

void makeReservation(vector<Movie>& movies) {
    displaySchedule(movies);

    int movieChoice, dateChoice, timeChoice, numSeats;
    cout << "\nSelect a movie:\n";
    for (int i = 0; i < movies.size(); ++i) {
        cout << i + 1 << ") " << movies[i].title << endl;
    }
    cout << "Enter movie number: ";
    cin >> movieChoice;

    if (movieChoice < 1 || movieChoice > movies.size()) {
        cout << "Invalid movie choice." << endl;
        return;
    }

    Movie& selectedMovie = movies[movieChoice - 1];

    vector<string> dates;
    for (const auto& movie : movies) {
        if (movie.date == selectedMovie.date) {
            dates.push_back(movie.date);
        }
    }

    cout << "\nSelect a date:\n";
    for (int i = 0; i < dates.size(); ++i) {
        cout << i + 1 << ") " << dates[i] << endl;
    }
    cout << "Enter date number: ";
    cin >> dateChoice;

    if (dateChoice < 1 || dateChoice > dates.size()) {
        cout << "Invalid date choice." << endl;
        return;
    }

    cout << "\nSelect a time slot:\n";
    for (int time = 0; time < NUM_TIMES; ++time) {
        int availableSeats = count(selectedMovie.availableSeats[time].begin(), selectedMovie.availableSeats[time].end(), true);
        cout << time + 1 << ") " << (time == 0 ? "12:00" : time == 1 ? "15:00" : time == 2 ? "18:00" : "21:00") << " - " << availableSeats << " seats left" << endl;
    }
    cout << "Enter time slot number: ";
    cin >> timeChoice;

    if (timeChoice < 1 || timeChoice > NUM_TIMES) {
        cout << "Invalid time slot choice." << endl;
        return;
    }

    cout << "Enter the number of seats to reserve: ";
    cin >> numSeats;

    int availableSeats = count(selectedMovie.availableSeats[timeChoice - 1].begin(), selectedMovie.availableSeats[timeChoice - 1].end(), true);
    if (numSeats > availableSeats) {
        cout << "Not enough available seats for this time slot." << endl;
        return;
    }

    string customerName;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, customerName);

    Reservation reservation;
    reservation.customerName = customerName;
    reservation.movieTitle = selectedMovie.title;
    reservation.date = dates[dateChoice - 1];
    reservation.timeSlot = timeChoice;

    int seatsReserved = 0;
    for (int i = 0; i < COLS && seatsReserved < numSeats; ++i) {
        if (selectedMovie.availableSeats[timeChoice - 1][i]) {
            selectedMovie.availableSeats[timeChoice - 1][i] = false;
            reservation.seatNumber = i + 1;
            seatsReserved++;
            cout << "Successfully reserved seat " << reservation.seatNumber << endl;
        }
    }
}