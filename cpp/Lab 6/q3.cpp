// #include <iostream>

// using namespace std;

// int mystery(int a, int b);

// int main() {
//     int x = 0;
//     int y = 0;
//     cout << "Enter two integers: ";
//     cin >> x >> y;
//     cout << "The result is " << mystery(x, y) << endl;
//     return 0;
// }

// int mystery(int a, int b) {
//     if (a == 0 || b == 0) {
//         return 0;
//     } else if (b == 1) {
//         return a;
//     } else if (b == -1) {
//         return -a;
//     } else if (b < 0) {
//         return -mystery(a, -b);
//     } else {
//         return a + mystery(a, b - 1);
//     }
// }

#include <iostream>
using namespace std;
int mystery(int, int);
int main()
{
    int x = 0;
    int y = 0;
    cout << "Enter two integers: ";
    cin >> x >> y;
    cout << endl;
    while (y <= 0) {
            cout << "Number must be positive. Please enter again: ";
            cin >> x >> y;
    }

    cout << "The result is " << mystery(x, y) << endl;
    return 0;
}
int mystery(int a, int b)
{
    if (b == 1)
    { // Base case
        return a;
    }
    else if (a == 0) 
    {
       return 0;
    }
    else
    { // Recursion step
        return a + mystery(a, b - 1);
    }
}