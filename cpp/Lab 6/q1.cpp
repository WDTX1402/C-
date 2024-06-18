#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Find_Smallest {
public:
    vector<int> sorting(vector<int> &v) {
        sort(v.begin(), v.end());
        return v;
    }
};

int main () {
    Find_Smallest find_smallest;
    int max;
    vector<int> v;
    cout << "Enter the number of integers: ";
    cin >> max;


    while (max <= 0) {
        cout << "Number must be positive. Please enter again: ";
        cin >> max;
    }

    cout << "Enter " << max << " integers: ";
    for(int i = 0; i < max; i++) {
        int input;
        cin >> input;
        v.push_back(input);
    }

    vector<int> sortedNums = find_smallest.sorting(v);

    cout << "The smallest number is " << v[0] << endl;
    return 0;
}
