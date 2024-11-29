#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
#include <cmath>   // for round round round
using namespace std;

int main() {
    int n, x;
    cout << "Enter number of students: ";
    cin >> n;

    vector<int> scores(n);
    cout << "Enter scores: ";
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    cout << "Enter score to count: ";
    cin >> x;

    int countX = count(scores.begin(), scores.end(), x);
    cout << "Count of " << x << ": " << countX << endl;

    sort(scores.begin(), scores.end(), greater<int>());
    cout << "Sorted scores: ";
    for (int score : scores) {
        cout << score << " ";
    }
    cout << endl;

    int total = accumulate(scores.begin(), scores.end(), 0);
    int average = round((double)total / n);
    cout << "Average score: " << average << endl;

    int topScore = scores.front(); 
    int bottomScore = scores.back();
    cout << "Top score: " << topScore << endl;
    cout << "Bottom score: " << bottomScore << endl;

    return 0;
}
