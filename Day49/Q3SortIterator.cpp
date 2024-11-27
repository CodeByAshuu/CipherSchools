#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<string, int>> sortMap(const map<string, int>& m) {
    // Convert map to vector
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;
    });

    return v;
}

int main() {
    map<string, int> m1 = {{"Alice", 50}, {"Bob", 70}, {"Charlie", 60}};
    vector<pair<string, int>> v1 = sortMap(m1);

    cout << "Result 1: ";
    for (const auto& p : v1) {
        cout << "{\"" << p.first << "\", " << p.second << "} ";
    }
    cout << endl;
    map<string, int> m2 = {{"X", 100}, {"Y", 80}};
    vector<pair<string, int>> v2 = sortMap(m2);

    cout << "Result 2: ";
    for (const auto& p : v2) {
        cout << "{\"" << p.first << "\", " << p.second << "} ";
    }
    cout << endl;

    return 0;
}
