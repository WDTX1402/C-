#include <iostream>
#include <string>

int main() {
        cout << "Enter output size: ";
        int size;
        cin >> size;
        int i = 0;
        while (i < size) {
            int j = 0;
            while (j <= i) {
                cout << "*";
                j++;
            }
            cout << "\n";
            i++;
        }
            
}

