// #include <iostream>

// int main() {
//     const int size = 9; // The size of the pattern
//     for (int row = 0; row < size; ++row) {
//         for (int col = 0; col < size; ++col) {
//             // Check if we're on the border, if so, print '#'
//             if (row == 0 || row == size - 1 || col == 0 || col == size - 1) {
//                 std::cout << "#";
//             }
//             // Check if we're inside the hourglass pattern
//             else if ((row <= col && row + col <= size - 1) || (row >= col && row + col >= size - 1)) {
//                 std::cout << "*";
//             }
//             // Else, we print a space
//             else {
//                 std::cout << " ";
//             }
//         }
//         std::cout << "\\n"; // Newline character for each row
//     }
//     return 0;
// }

#include <iostream>
#include <iomanip>  // For setprecision
#include <string>
using namespace std;

int main() {
    double num = 123.4567;

    cout << "Default format: " << num << endl;

    // Fixed format with precision
    cout << fixed;
    cout << setprecision(2);  // Setting precision to 2 decimal places
    cout << "Fixed format: " << num << endl;

    // Scientific format with precision
    cout << scientific;
    cout << setprecision(2);  // Setting precision to 3 decimal places
    cout << "Scientific format: " << num << endl;

    cout << string(10, '#');

    return 0;
}
