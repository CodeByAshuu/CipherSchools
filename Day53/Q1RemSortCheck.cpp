#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, checkID;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> itemIDs(n);
    cout << "Enter the item IDs: ";
    for (int i = 0; i < n; ++i) {
        cin >> itemIDs[i];
    }

    cout << "Enter the item ID to check: ";
    cin >> checkID;

    set<int> uniqueItems(itemIDs.begin(), itemIDs.end());

    vector<int> sortedItems(uniqueItems.begin(), uniqueItems.end());
    sort(sortedItems.begin(), sortedItems.end());

    cout << "Unique item IDs: ";
    for (int id : uniqueItems) {
        cout << id << " ";
    }
    cout << endl;

    cout << "Sorted unique item IDs: ";
    for (int id : sortedItems) {
        cout << id << " ";
    }
    cout << endl;

    if (uniqueItems.find(checkID) != uniqueItems.end()) {
        cout << "Available" << endl;
    } else {
        cout << "Not Available" << endl;
    }

    cout << "Total number of unique items: " << uniqueItems.size() << endl;

    return 0;
}
