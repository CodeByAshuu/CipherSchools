#include <iostream>
#include <set>
using namespace std;

set<int> mergeSets(const set<int>& set1, const set<int>& set2) {
    set<int> mergedSet(set1.begin(), set1.end());
    mergedSet.insert(set2.begin(), set2.end());
    return mergedSet;
}

void displaySet(const set<int>& resultSet) {
    cout << "{ ";
    for (const int& element : resultSet) {
        cout << element << " ";
    }
    cout << "}" << endl;
}

int main() {
    set<int> set1 = {1, 3, 5};
    set<int> set2 = {2, 3, 4, 6};

    set<int> mergedSet = mergeSets(set1, set2);
    cout << "Merged Set: ";
    displaySet(mergedSet);

    set<int> set3 = {7, 8};
    set<int> set4 = {8, 9, 10};

    set<int> mergedSet2 = mergeSets(set3, set4);
    cout << "Merged Set: ";
    displaySet(mergedSet2);

    return 0;
}
