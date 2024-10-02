#include <iostream>
#include <vector>
using namespace std;

int maxSubArraySum(vector<int>& arr, int n) {
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);

        maxSum = max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int maxSum = maxSubArraySum(arr, n);

    cout << "The maximum sum of subarray is: " << maxSum << endl;

    return 0;
}
