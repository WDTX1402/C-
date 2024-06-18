#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

class GuessNumberGame {
public:
    int randomnumber;

    GuessNumberGame() {
        srand(static_cast<unsigned int>(time(nullptr))); 
        randomnumber = rand() % 101;
    }
    int play (int guess) {
        if (guess == randomnumber) {
            return 0;
        } else if (guess < randomnumber) {
            return 1;
        } else {
            return 2;
        }
    } 
};

int main() {
    GuessNumberGame game;
    int guess;
    const int maxTries = 10;
    int tries = 0;
    int status;

    cout << "Guess the number between (0 and 100):\n";
    
    while (tries < maxTries) {
        if (tries == 0) {
        cout << "Enter your guess: ";
            tries++;
        } else {
        cin >> guess;
        if (cin >> guess) {
            status = game.play(guess);

        if (status == 0) {
            ;
            break;
        } else if (status == 1) {
            cout << "Higher than your number. Try again: ";
        } else {
            cout << "Lower than your number. Try again: ";
        }

        tries++;

        if (tries == maxTries) {
            cout << "Game over! The correct number was " << game.randomnumber << ".\n";
        }
        } else {
            cout << "Error";
            cin.clear();
            cin.ignore(100, '\n');
        }
    
    }
    }
    return 0;
}
