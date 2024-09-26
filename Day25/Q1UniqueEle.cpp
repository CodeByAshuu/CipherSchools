#include <iostream>
#include <vector>

using namespace std;

int findSingleNumber(const vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    while (n % 2 == 0) {
        cout << "Invalid input! The number of elements must be odd. Enter again: ";
        cin >> n;
    }

    vector<int> nums(n);
    cout << "Enter the elements of the array (all elements appear twice except for one):\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int singleNumber = findSingleNumber(nums);
    cout << "The single number is: " << singleNumber << endl;

    return 0;
}
