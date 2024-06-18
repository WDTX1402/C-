#include <string>
#include <iostream>

using namespace std;

int main () {
    int inpus;
    cout << "Enter some shit pls: " << endl;
    cin >> inpus;

    for (int i = 1; i <= inpus; i++){
        for( int j =0; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = inpus - 1 ; i >= 0; i--) {
        for(int j = 0 ; j < i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}