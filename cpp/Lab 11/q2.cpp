    #include <fstream>
    #include <sstream>
    #include <iostream>
    #include <vector>
    #include <string>
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
                for (int rnd = 0; rnd < movie.round.size(); ++rnd) {
                    if (day < movie.available_seats.size() && rnd < movie.available_seats[day].size()) {
                        cout << "Round " << movie.round[rnd] << ": " << movie.available_seats[day][rnd] << " seats available." << endl;
                    }
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

    bool cancelReservation(vector<Movie>& movies, const string& movieTitle, const string& movieDate, const string& selectedRound, int cancel_num) {
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

                if (dateIDX != -1 && roundIDX != -1 ) {
                    if (movie.available_seats[dateIDX][roundIDX] + cancel_num >= 10){
                       cout << "Seats have not been reserved in the first place" << endl;
                       return false;
                    }
                    movie.available_seats[dateIDX][roundIDX] += cancel_num;
                    cout << "Successfully canceled " << cancel_num << " seats for " << movieTitle << " on " << movieDate << " for round " << selectedRound << "." << endl;
                    return true;
                } else {
                    if (dateIDX == -1) cout << "Date not found." << endl;
                    if (roundIDX == -1) cout << "Round not found." << endl;
                    return false;
                }
            }
        }
        cout << "Movie not found." << endl;
        return false;
    }


    void saveData(const vector<Movie>& movies, const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }

        for (const auto& movie : movies) {
            file << movie.title << endl;
            for (const auto& date : movie.date) {
                file << date << ",";
            }
            file << endl;
            for (const auto& round : movie.round) {
                file << round << ",";
            }
            file << endl;
            for (const auto& seatsPerDate : movie.available_seats) {
                for (const auto& seats : seatsPerDate) {
                    file << seats << ",";
                }
                file << ";";
            }
            file << endl;
        }
        file.close();
        cout << "Data saved successfully." << endl;
    }
    void loadData(vector<Movie>& movies, const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading: " << filename << endl;
            return;
        }

        movies.clear(); 
        string line;
        while (getline(file, line)) {
            Movie movie;
            movie.title = line;

            getline(file, line);
            stringstream dateStream(line);
            string date;
            while (getline(dateStream, date, ',')) {
                if (!date.empty()) movie.date.push_back(date);
            }

            getline(file, line);
            stringstream roundStream(line);
            string round;
            while (getline(roundStream, round, ',')) {
                if (!round.empty()) movie.round.push_back(round);
            }

            getline(file, line);
            stringstream seatStream(line);
            string seatsPerDate;
            while (getline(seatStream, seatsPerDate, ';')) {
                vector<int> seats;
                stringstream seatCountStream(seatsPerDate);
                string seat;
                while (getline(seatCountStream, seat, ',')) {
                    if (!seat.empty()) seats.push_back(stoi(seat));
                }
                if (!seats.empty()) movie.available_seats.push_back(seats);
            }

            movies.push_back(movie);
        }
        file.close();
    }

    int main() {
        vector<Movie> movies;
        // {
        //     {"Poor Things", 
        //      {"2024-03-01", "2024-03-02", "2024-03-03"}, 
        //      {"12:10", "13:10", "15:00"}, 
        //      {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}}}, 
            
        //     {"เหมรย", 
        //      {"2024-03-01", "2024-03-02", "2024-03-03"}, 
        //      {"12:10", "13:10", "14:10"}, 
        //      {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}}},

        //     {"4KingsII", 
        //      {"2024-03-01", "2024-03-02", "2024-03-03"}, 
        //      {"12:10", "13:10", "14:10"}, 
        //      {{10, 10, 10}, {10, 10, 10}, {10, 10, 10}}}
        // };

        string filename = "reservations.txt";

        loadData(movies, filename);

        int choice;
        do {
            cout << "1. View Schedule\n2. Make Reservation\n3. Cancel Reservation\n4. Save Data\n5. Exit\nEnter choice: ";
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
                    if (select_movie >= movies.size()){
                        cout << "Not an option" <<endl;
                        break;
                    }
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
                case 3: {
                    string movieTitle, movieDate, selectedRound;
                    int cancel_num;
                    for (int i = 0 ; i < movies.size(); i++) {
                            cout << i + 1<< ".) Movie: " << movies[i].title << endl;
                    }
                    cout << "Choose a movie: ";
                    cin.ignore(); 
                    int select_movie;
                    cin >> select_movie; 
                    if (select_movie >= movies.size()){
                        cout << "Not an option)" <<endl;
                        break;
                    }
                    movieTitle = movies[select_movie- 1].title;
        
                    for (int j = 0 ; j < movies[select_movie-1].date.size(); j++){
                            cout << j + 1<< ".) Date: " << movies[select_movie-1].date[j] << endl;
                    }
                    cout << "Choose a date: ";
                    cin.ignore(); 
                    int select_date;
                    cin >> select_date;
                    movieDate= movies[select_movie- 1].date[select_date-1]; 
                    cout << "Enter round (HH:MM) for cancellation: ";
                    cin >> selectedRound;
                    cout << "Enter number of seats to cancel: ";
                    cin >> cancel_num;

                    if (!cancelReservation(movies, movieTitle, movieDate, selectedRound, cancel_num)) {
                        cout << "Cancellation failed. Please check the details and try again." << endl;
                    }
                    break;
                }
                case 4:
                    saveData(movies, filename);
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice, please try again.\n";
            }
        } while (choice != 5);

        return 0;
    }