#include <iostream>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time to seed the random number generator

using namespace std;

int find_max(const int arr[], int index, int size) {
    if (index >= size - 1) {
        return arr[index];
    }
    int maxInRest = find_max(arr, index + 1, size);

    return (arr[index] > maxInRest) ? arr[index] : maxInRest;
}


int main() {
  
    srand(static_cast<unsigned int>(time(nullptr)));

    const int SIZE = 10;
    int numbers[SIZE];

    cout << "Generated 10 random integers between 1 and 100: ";
    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = rand() % 100 + 1; 
        cout << numbers[i] << " ";
    }
    cout << endl;

    int maxNumber = find_max(numbers, 0, SIZE);

    cout << "The largest element in the array is: " << maxNumber << endl;

    return 0;
}
