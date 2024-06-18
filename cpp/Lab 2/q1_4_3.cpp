#include <iostream>
#include <string>

int main() {
    cout << "Please enter P1 name: ";
    string p1_name;
    getline(cin, p1_name);

    cout << "Please enter P2 name: ";
    string p2_name;
    getline(cin, p2_name);

    string first_name = "Player 1: " + p1_name;
    string sec_name = "Player 2: " + p2_name;
    

    int long_length = 0;
    if(first_name.length() > sec_name.length()) {
        long_length = first_name.length();
    } else {
        long_length = sec_name.length();
    }

    int total_row = 9;
    int row = 1;
    while (row <= 9) {
        if (row == 1 || row == 9) {
            cout << "+";
            for(int i = 0; i <= long_length +1 ; ++i) {
                cout << '=';
            }
            cout << "+";
            cout << endl;
        } else if (row == 5) {
            cout << "+";
            for(int i = 0; i <= long_length +1 ; ++i) {
                cout << '-';
            }
            cout << "+";
            cout << endl;
        } else if (row == 3) {
            cout << "| " << first_name;
            for (int i = 0 ; i <= long_length - first_name.length() ; i++) {
                cout << " ";
            }
            cout << "|" << endl;
        } else if (row == 7) {
            cout << "| " << sec_name;
            for (int i = 0 ; i <= long_length - sec_name.length() ; i++) {
                cout << " ";
            }
            cout << "|" << endl;;
        } else {
            cout << "|";
            for(int i = 0; i <= long_length +1; ++i) {
                cout << ' ';
            }
            cout << "|" << endl;
        }
        row++;
    }

    return 0;
}

