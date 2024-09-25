#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(const vector<int>& arr) {
    int maxCount = 0;
    int currentCount = 0; 

    for (int num : arr) {
        if (num == 1) {
            currentCount++;
        } else {
            maxCount = max(maxCount, currentCount);
            currentCount = 0;
        }
    }

    maxCount = max(maxCount, currentCount);

    return maxCount;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the binary array (0s and 1s only):\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = findMaxConsecutiveOnes(arr);
    
    cout << "Maximum number of consecutive 1's: " << result << endl;

    return 0;
}
