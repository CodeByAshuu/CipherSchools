#include <iostream>
using namespace std;

void checkOddOrEven(int num) {
    if (num % 2 == 0) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;
    checkOddOrEven(number);

    return 0;
}
