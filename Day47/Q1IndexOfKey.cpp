#include <iostream>
#include <vector>
using namespace std;

int findIndex(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> vec1 = {1, 3, 5, 7, 9};
    int target1 = 7;
    cout << "Output: " << findIndex(vec1, target1) << endl;

    vector<int> vec2 = {2, 4, 6, 8};
    int target2 = 10;
    cout << "Output: " << findIndex(vec2, target2) << endl;

    return 0;
}
