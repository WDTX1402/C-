#include <iostream>
#include <string>

using namespace std;

void reverseString(const string& str, int index) {
    if (index == str.size()) {
        return; 
    }
    reverseString(str, index + 1); 
    cout << str[index]; 
}


int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    cout << "Reversed string: ";
    reverseString(input, 0);
    cout << endl;

    return 0;
}
