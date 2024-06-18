#include <iostream>
#include <string>

int main() {
        cout << "Enter output size: ";
        int size;
        cin >> size;
        int i = 1;
        while (i < size) {
            int j = 0;
            while (j < i) {
                cout << "*";
                j++;
            }
            cout << "\n";
            i++;
        }
        int c = size;
        while (c > 0) {
            int b = 1;
            while (b <= c) {
                cout << "*";
                b++;
            }
            cout << "\n";
            c--;
        }
            
}

