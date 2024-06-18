#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

char patternCheck(const vector<vector<char>>& charVector) {
    int rows = charVector.size();
    int cols = charVector[0].size();

    if (rows != 4 || cols != 4) {
        return 'e';
    }

    vector<int> charCount(26, 0); 

    for (const auto& row : charVector) {
        for (char c : row) {
            if (isalpha(c)) {
                charCount[c - 'a']++;
            }
        }
    }

    vector<char> validChars;
    for (int i = 0; i < 26; i++) {
        if (charCount[i] == 4) {
            validChars.push_back('a' + i);
        }
    }

    if (validChars.empty()) {
        return 'n';
    }

    for (const auto& row : charVector) {
        for (char ch : validChars) {
            if (all_of(row.begin(), row.end(), [&](char c) { return c == ch; })) {
                return '-';
            }
        }
    }

    for (int col = 0; col < cols; col++) {
        for (char ch : validChars) {
            bool isVertical = true;
            for (int row = 0; row < rows; row++) {
                if (charVector[row][col] != ch) {
                    isVertical = false;
                    break;
                }
            }
            if (isVertical) {
                return '|';
            }
        }
    }

    for (char ch : validChars) {
        bool isDiagonal_L = true;
        for (int i = 0; i < rows; i++) {
            if (charVector[i][i] != ch) {
                isDiagonal_L = false;
                break;
            }
        }
        if (isDiagonal_L) {
            return '\\';
        }
    }

    for (char ch : validChars) {
        bool isDiagonal_R = true;
        for (int i = 0; i < rows; i++) {
            if (charVector[i][cols - 1 - i] != ch) {
                isDiagonal_R = false;
                break;
            }
        }
        if (isDiagonal_R) {
            return '/';
        }
    }

    return 'n';
}

int main() {
    vector<vector<char>> charVector(4);
    cout << "Enter your inputs: " << endl;

    for (int i = 0; i < 4; i++) {
        string line;
        cout << "Line " << i << ": ";
        cin >> line;

        for (char c : line) {
            charVector[i].push_back(c);
        }
    }

    // char input;

    // for (int i = 0; i < 4; i++) {
    //    vector<char> vec; 
    //    cout << "enter vector: ";
    //    for (int j = 0; j < 4; j++){
    //         cin >> input;
    //         vec.push_back(input);
    //    }
    //    charVector.push_back(vec);
    // } 

    
    char pattern = patternCheck(charVector);

    if (pattern == 'e') {
        cout << "Wrong input form" << endl;
    } else {
        cout << "Pattern: " << pattern << endl;
    }

    return 0;
}