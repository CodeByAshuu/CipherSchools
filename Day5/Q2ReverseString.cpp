#include <iostream>
#include <string>
using namespace std;

string reverseString(string str) {
    int n = str.length();

    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }

    return str;
}

int main() {
    string inputString;

    cout << "Enter a string: ";
    cin >> inputString;

    string reversedString = reverseString(inputString);

    cout << "Reversed string: " << reversedString << endl;

    return 0;
}
