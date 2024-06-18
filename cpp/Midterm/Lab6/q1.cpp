#include <iostream>
#include <string>
#include <vector>

using namespace std;

class smallest_int {
    private:
        int num_of_int;
        vector<int> inputs;
    public:
        void set_num(int x) {
            num_of_int = x;
        }

        void num_inputs (int x) {
            inputs.push_back(x);
        }

        int find_smallest() {
            int smol = 0;
            for(int i =0 ; i < num_of_int ; i++) {
                if (inputs[i] < smol) {
                    smol = inputs[i];
                }
            }
            return smol;
        }
};


int main() {
    smallest_int find_smol;
    cout << "Enter the number of integers: ";
    int num;
    cin >> num;

    while (num <= 0) {
        cout << "Number must be positive: ";;
        cin >> num;
    }

    find_smol.set_num(num);
    int i = 0;
    cout << "Enter integers: "<< endl;
    while (i < num) {
        int nums;
        cin >> nums;
        find_smol.num_inputs(nums);
        i++;
    }
    cout << "The smallest integer is: "<< find_smol.find_smallest() << endl;
    return 0;
}
