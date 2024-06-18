#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<double>& numbers) {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 1; i < numbers.size(); ++i) {
            if (numbers[i - 1] > numbers[i]) {
                swap(numbers[i - 1], numbers[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

int sqrt(int n) {
    if (n < 2) {
        return n;
    }
    int low = 1, high = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid == n) {
            return mid;
        } else if (mid * mid < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}
 

double calculate_mean(const vector<double>& numbers) {
    double sum = 0.0;
    for (double num : numbers) {
        sum += num;
    }
    int pre_result = (numbers.empty() ? 0.0 : sum / numbers.size() * 100);
    double result = pre_result / 100;
    return result;
}


double calculate_median(vector<double>& numbers) {
    bubble_sort(numbers);
    size_t size = numbers.size();
    if (size % 2 == 0) {
        int pre_result = ((numbers[size / 2 - 1] + numbers[size / 2]) / 2.0) * 100;
        double result = pre_result / 100;
            return result;
    } else {
        int pre_result = (numbers[size / 2]) * 100;
        double result = pre_result / 100;
            return result;
    }
}


double calculate_standard_deviation(const vector<double>& numbers, double mean) {
    double variance = 0.0;
    for (double num : numbers) {
        variance += (num - mean) * (num - mean);
    }
    int pre_result = (sqrt(variance / numbers.size())) *100;
    double result = pre_result / 100;
        return result;

}


int main() {
    vector<double> numbers;
    double value;

    cout << "Enter numbers (end with a non-numeric character): ";


    while (cin >> value) {
        numbers.push_back(value);
    }


    // cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double min = numbers[0];
    double max =numbers[0];

    for (double num : numbers) {
        if (num < min) min = num;
        if (num > max) max = num;
    }

    if (!numbers.empty()) {
  
        double mean = calculate_mean(numbers);
        double median = calculate_median(numbers);
        double std_dev = calculate_standard_deviation(numbers, mean);

    
        cout << "Mean: " << mean << endl;
        cout << "Median: " << median << endl;
        cout << "Standard Deviation: " << std_dev << endl;
        cout << "Minimum: " << min << endl;
        cout << "Maximum: " << max << endl;
    } else {
        cout << "No valid numbers were entered." << endl;
    }

    return 0;
}