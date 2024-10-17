#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> stations(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> stations[i];
        }

        int max_gap = max(stations[0], x - stations[n - 1]);

        for (int i = 1; i < n; ++i) {
            max_gap = max(max_gap, stations[i] - stations[i - 1]);
        }

        cout << max_gap << endl;
    }

    return 0;
}
