#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool frequencyComparator(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first; 
    }
    return a.second < b.second; 
}

vector<int> sortByFrequency(vector<int>& vec) {
    unordered_map<int, int> freqMap;
    for (int num : vec) {
        freqMap[num]++;
    }
    vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
    sort(freqVec.begin(), freqVec.end(), frequencyComparator);

    vector<int> sortedVec;
    for (auto& elem : freqVec) {
        sortedVec.insert(sortedVec.end(), elem.second, elem.first);
    }

    return sortedVec;
}

int main() {
    vector<int> vec1 = {4, 5, 6, 5, 4, 3};
    vector<int> sortedVec1 = sortByFrequency(vec1);
    cout << "Sorted vector: ";
    for (int num : sortedVec1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> vec2 = {9, 9, 8, 7, 7, 7};
    vector<int> sortedVec2 = sortByFrequency(vec2);
    cout << "Sorted vector: ";
    for (int num : sortedVec2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
