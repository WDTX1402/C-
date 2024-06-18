#include <iostream>
#include <cstring>
#include <tuple>

using namespace std;


tuple<int, int> mystery3(const char*); 
void reverseString(char*); 

int main() {
    try {
        const int maxStringLength = 79;
        char string1[maxStringLength + 1];
        cout << "Enter a string: ";

        cin.getline(string1, maxStringLength + 1);

        tuple<int, int> result = mystery3(string1);
        cout << "Length of the string: " << get<0>(result) << endl;
        cout << "Number of vowels in the string: " << get<1>(result) << endl;

        cout << "Original string: " << string1 << endl;
        reverseString(string1);
        cout << "Reversed string: " << string1 << endl;

    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}

tuple<int, int> mystery3(const char* s) {
    unsigned int length = 0;
    unsigned int vowelCount = 0;

    while (*s != '\0') { 
        ++length;
        // Check for vowels
        if (strchr("aeiouAEIOU", *s) != nullptr) {
            ++vowelCount;
        }
        ++s;
    }

    return make_tuple(length, vowelCount);
}

void reverseString(char* s) {
    int length = strlen(s);
    for (int i = 0; i < length / 2; ++i) {
        swap(s[i], s[length - i - 1]);
    }
}
