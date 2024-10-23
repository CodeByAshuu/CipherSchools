#include <iostream>
using namespace std;

int sum_of_digits(int n) {
    if (n == 0)
        return 0;

    return (n % 10) + sum_of_digits(n / 10);
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    int result = sum_of_digits(n);
    cout << "Sum of digits of " << n << " is: " << result << endl;

    return 0;
}
