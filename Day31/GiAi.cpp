#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> findNearestSmallerElements(vector<int>& A, int n) {
    stack<int> s;
    vector<int> G(n);

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= A[i]) {
            s.pop();
        }

        if (s.empty()) {
            G[i] = -1;
        }
        else {
            G[i] = s.top();
        }

        s.push(A[i]);
    }

    return G;
}

int main() {
    int n;
    
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> G = findNearestSmallerElements(A, n);

    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++) {
        cout << G[i] << " ";
    }
    cout << endl;

    return 0;
}
