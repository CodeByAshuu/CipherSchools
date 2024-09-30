#include <iostream>
using namespace std;

void sumOfOddEven(int arr[], int size, int &oddSum, int &evenSum) {
    oddSum = 0;
    evenSum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }
}

int main() {
    int size, oddSum, evenSum;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    sumOfOddEven(arr, size, oddSum, evenSum);

    cout << "Sum of odd numbers: " << oddSum << endl;
    cout << "Sum of even numbers: " << evenSum << endl;

    return 0;
}
