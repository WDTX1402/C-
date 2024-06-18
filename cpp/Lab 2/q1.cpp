// #include <iostream>
// #include <string>

// int main()
//         {
//         cout << "Please enter P1 name: ";
//         string p1_name;
//         cin >> p1_name;
//         cout << "Please enter P2 name: ";
//         string p2_name;
//         cin >> p2_name;
//         cout << "Player 1: " << p1_name << endl;
//         cout << "Player 2: " << p2_name << endl;
//         return 0;
//     }

#include <iostream>
#include <string>

int main() {
    cout << "Please enter P1 name: ";
    string p1_name;
    getline(cin, p1_name);

    cout << "Please enter P2 name: ";
    string p2_name;
    getline(cin, p2_name);

    string first_name = "Player 1: " + p1_name;
    string combined = first_name + " * " + "Player 2: " + p2_name + " ";

    int frame_length = combined.length();
    for(int i = 0; i <= frame_length +1 ; ++i) {
        cout << '*';
    }
    cout << endl;

    cout << "*";
    for(int i = 0; i <= frame_length; ++i) {
        if (i == first_name.length() + 1) {
            cout << '*';
        }
        else {
        cout << ' ';
        }
    }
    cout << "*" << endl;

    cout << "* " << combined << "*" << endl;

    cout << "*";
    for(int i = 0; i <= frame_length; ++i) {
        if (i == first_name.length() + 1) {
            cout << '*';
        }
        else {
        cout << ' ';
        }
    }
    cout << "*" << endl;
    
    for(int i = 0; i <= frame_length +1 ; ++i) {
        cout << '*';
    }
    cout << endl;

    return 0;
}
