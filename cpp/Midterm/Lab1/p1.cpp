#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter P1 name: ";
    string p1_name;
    getline(cin, p1_name);
    cout << "Please enter P2 name: ";
    string p2_name;
    getline(cin, p2_name);

    string p1 = "Player 1: " + p1_name;
    string p2 = "Player 2: " + p2_name;

    int max;
    if (p1.length() > p2.length()) {
        max = p1.length();
    } else {
        max = p2.length();
    }
    
    int j = 0;

    while (j < 9) {
    if (j == 0 || j== 4 || j == 8) { 
            for (int i = 0; i < max + 4 ; i++) {
            cout << "*" ;
            if (i == (max + 4) - 1) {
                cout << endl;
            }
        }
    } else if (j == 2) {
        cout << "* " + p1 + " *"<< endl;
    } else if (j == 6) {
        cout << "* " + p2 + " *" << endl ;
    } else {
        for (int i = 0; i < max + 4 ; i++)
            if (i ==0) {
                cout << "*";
            } else if (i == (max + 4) - 1) {
                cout << "*" << endl;
            } else {
                cout << " ";
            }
        }
        j++;
    }
    return 0;
}