#include <iostream>
#include <vector> //vector hai bhai vector
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int result = a[0];

        for (int i = 1; i < n; i += 2) {
            result = max(result, a[i]);
        }

        cout << result << endl;
    }

    return 0;
}
