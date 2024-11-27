#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findUnionAndIntersection(vector<int>& arr1, vector<int>& arr2) {
    set<int> unionSet, intersectionSet;

    for (int num : arr1) {
        unionSet.insert(num);
    }

    for (int num : arr2) {
        if (unionSet.count(num)) {
            intersectionSet.insert(num); 
        }
        unionSet.insert(num);
    }

    // Display the Union
    cout << "Union = {";
    for (auto it = unionSet.begin(); it != unionSet.end(); ++it) {
        if (it != unionSet.begin()) cout << ", ";
        cout << *it;
    }
    cout << "}" << endl;
    cout << "Intersection = {";
    for (auto it = intersectionSet.begin(); it != intersectionSet.end(); ++it) {
        if (it != intersectionSet.begin()) cout << ", ";
        cout << *it;
    }
    cout << "}" << endl;
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {2, 3, 4};

    cout << "For arr1 = {1, 2, 3} and arr2 = {2, 3, 4}:" << endl;
    findUnionAndIntersection(arr1, arr2);

    vector<int> arr3 = {5, 6, 7};
    vector<int> arr4 = {8, 9};

    cout << "\nFor arr1 = {5, 6, 7} and arr2 = {8, 9}:" << endl;
    findUnionAndIntersection(arr3, arr4);

    return 0;
}
