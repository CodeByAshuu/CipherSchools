#include <iostream>
#include <vector>
using namespace std;

void generateParenthesisHelper(int n, int open, int close, string current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }
    if (open < n) {
        generateParenthesisHelper(n, open + 1, close, current + "(", result);
    }

    if (close < open) {
        generateParenthesisHelper(n, open, close + 1, current + ")", result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(n, 0, 0, "", result);
    return result;
}

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    vector<string> validCombinations = generateParenthesis(n);

    cout << "Valid combinations of parentheses are: " << endl;
    for (const string& combination : validCombinations) {
        cout << combination << endl;
    }

    return 0;
}
