#include <random>
#include <iostream>
#include <iomanip>
#include <cmath>

class Rand_double {
public:
    Rand_double(double low, double high) : dist(low, high), re(random_device{}()) {}

    double operator()() {
        return dist(re);
    }

private:
    default_random_engine re;
    uniform_real_distribution<double> dist;
};

int main() {
    const double rnd_min = -1.0, rnd_max = 1.0;
    Rand_double rnd(rnd_min, rnd_max);

    const int N = 10000;
    int points_inside = 0;

    for (int i = 0; i < N; ++i) {
        double x = rnd();
        double y = rnd();

        if (x * x + y * y <= 1) {
            ++points_inside;
        }
    }

    double pi_estimate = 4 * (points_inside / static_cast<double>(N));

    cout << fixed << setprecision(3);
    cout << "Estimated Pi " << pi_estimate << endl;

    return 0;
}