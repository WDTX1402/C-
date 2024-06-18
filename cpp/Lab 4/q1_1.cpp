#include <iostream>
#include <string>
#include <vector>

using namespace std;

void lshift(vector<int>& sequence, int num) {
    sequence.erase(sequence.begin(), sequence.begin() + num);
}

void rshift(vector<int>& sequence, int num) {
    for (int i = 0; i < num; i++) {
        sequence.insert(sequence.begin(), 0);
    }
}

int main() {
    vector<int> og_sequence = {1, 2, 3, 4, 5};
    int num1 = 2;
    int num2 = 3;
    
    cout << "Original sequence: ";
    for (int i = 0; i < og_sequence.size(); i++) {
        cout << og_sequence[i] << " ";
    }
    cout << "" << endl;


    lshift(og_sequence, num1);

    cout << "After lshift by " << num1 << ": ";
    for (int i = 0; i < og_sequence.size(); i++) {
        cout << og_sequence[i] << " ";
    }
    cout << "" << endl;


    rshift(og_sequence, num2);
    cout << "After rshift by " << num2 << ": ";
    for (int i = 0; i < og_sequence.size(); i++) {
        cout << og_sequence[i] << " ";
    }
    cout << "" << endl;

    return 0;
}
