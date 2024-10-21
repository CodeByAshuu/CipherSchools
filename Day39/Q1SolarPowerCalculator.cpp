#include <iostream>
using namespace std;

double pow(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }

    double result = 1.0;
    double current_product = x;

    while (N > 0) {
        if (N % 2 == 1) {
            result *= current_product;
        }
        current_product *= current_product;
        N /= 2;
    }

    return result;
}

int main() {
    double x;
    int n;
    cout << "Enter the daily energy production (x): ";
    cin >> x;
    cout << "Enter the number of days (n): ";
    cin >> n;

    double totalEnergy = pow(x, n);

    cout << "Total energy generated over " << n << " days: " << totalEnergy << " kWh" << endl;

    return 0;
}
