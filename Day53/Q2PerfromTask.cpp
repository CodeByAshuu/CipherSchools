#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n, searchNum;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << "Enter the number to search for: ";
    cin >> searchNum;

    int evenCount = count_if(numbers.begin(), numbers.end(), [](int x) { return x % 2 == 0; });
    int oddCount = n - evenCount;

    long long cumulativeProduct = accumulate(numbers.begin(), numbers.end(), 1LL, multiplies<long long>());

    bool found = find(numbers.begin(), numbers.end(), searchNum) != numbers.end();

    sort(numbers.rbegin(), numbers.rend());

    cout << "Count of even numbers: " << evenCount << endl;
    cout << "Count of odd numbers: " << oddCount << endl;
    cout << "Cumulative product: " << cumulativeProduct << endl;
    cout << (found ? "Found" : "Not Found") << endl;
    cout << "Sorted in descending order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
