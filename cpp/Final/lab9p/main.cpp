#include <iostream>
#include <vector>
#include <limits>
#include "Album.h"

int main() {
    vector<Album> albums;
    albums.emplace_back("Abbey Road", "The Beatles", 19.99, 5);
    albums.emplace_back("The Dark Side of the Moon", "Pink Floyd", 21.99, 3);
    albums.emplace_back("Hotel California", "Eagles", 15.99, 4);
    albums.emplace_back("Back in Black", "AC/DC", 20.99, 2);
    albums.emplace_back("Rumours", "Fleetwood Mac", 16.99, 3);
    albums.emplace_back("Thriller", "Michael Jackson", 18.99, 5);
    albums.emplace_back("The Wall", "Pink Floyd", 22.99, 2);
    albums.emplace_back("Led Zeppelin IV", "Led Zeppelin", 17.99, 3);
    int choice;
    bool running = true;
    while (running) {
        cout << "Online Music Store Menu:\n"
                  << "1. List all albums\n"
                  << "2. Purchase an album\n"
                  << "3. Display sales statistics\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                for(int i=0; i< albums.size(); i++){
                    cout <<i+1<< "." << albums[i].getTitle() 
                         << " by " << albums[i].getArtist() 
                         << " - " << albums[i].getprice() << "$"
                         << " (" <<  albums[i].getCopiesAvailable() 
                         <<" copies available " <<  ")\n";
                }
                cout << "\n" << endl;
                break;
            case 2:
                    int albumNumber;
                    cout << "Enter the album number you wish to purchase: ";
                    cin >> albumNumber;
                    
                    if (cin.fail() || albumNumber < 1 || albumNumber > albums.size()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid album number. Please try again.\n";
                    } else {
                        albumNumber -= 1;
                        
                        if (albums[albumNumber].getCopiesAvailable() > 0) {
                            albums[albumNumber].purchaseAlbum();
                            cout << "You have successfully purchased " 
                                    << albums[albumNumber].getTitle() << " by " 
                                    << albums[albumNumber].getArtist() << ".\n\n";
                        } else {
                            cout << "Sorry, the album is out of stock.\n";
                        }
                    }
                    break;

            case 3:
                cout << "Total albums in inventory: " << Album::getTotalAlbums() << endl;
                cout << "Total sales made: $" << Album::getTotalSales() << endl;
                cout << "\n" << endl;
                break;
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    }

    cout << "Thank you for using the Online Music Store.\n";
    return 0;
}