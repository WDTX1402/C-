#include <iostream>
#include <vector>
#include <string>

using namespace std;

// vector<double> remove_negative(vector<double>& vec) {
//     vector<double> vec2;
//     for (int i =0; i < vec.size(); i++) {
//         if (vec[i] >= 0.0) {
//             vec2.push_back(vec[i]);
//         } else {
//             continue;
//         }
//     }
//     return vec2;
// }

vector<double> remove_negative(vector<double> vec) {
    vector<double> vec2;
    for (auto ele: vec) {
        if (ele >= 0.0) {
            vec2.push_back(ele);
        } else {
            continue;
        }
    }
    return vec2;
}


int main() {
    vector<double> vec {0.8, -5.1, 1.6, -6.5, 10.5};
    cout << "Original vector: ";
    for (auto ele: vec) {
        cout << ele << " ";
    }
    cout << endl;

    vector<double> vec2 = remove_negative(vec);

    cout << "Vector after removing negative numbers: ";
     for (int i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    return 0;
}