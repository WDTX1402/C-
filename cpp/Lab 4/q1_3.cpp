#include <iostream>
#include <list>
#include <string>

using namespace std;

bool isNegative(double n) {
    return n < 0;
}

void remove_negative(list<double>& lst) {
    lst.remove_if(isNegative);
}

int main() {
    list<double> lst {0.8, -5.1, 1.6, -6.5, 10.5};

    cout << "Original list: ";
    for (double element : lst) {
        cout << element << " ";
    }
    cout << endl;

    remove_negative(lst);

    cout << "List after removing negative numbers: ";
    for (double element : lst) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
