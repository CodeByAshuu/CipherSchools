#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateRight(vector<int>& vec, int k) {
    int n = vec.size();
    k = k % n;
    if (k == 0) return;
    rotate(vec.rbegin(), vec.rbegin() + k, vec.rend());
}

int main() {
    vector<int> vec1 = {1, 2, 3, 4, 5};
    int k1 = 2;
    rotateRight(vec1, k1);
    cout << "Output: ";
    for (int num : vec1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> vec2 = {10, 20, 30, 40};
    int k2 = 1;
    rotateRight(vec2, k2);
    cout << "Output: ";
    for (int num : vec2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
