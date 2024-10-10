#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

string frequencySort(string s) {
    unordered_map<char, int> freqMap;
    for (char ch : s) {
        freqMap[ch]++;
    }

    string result = "";
    while (!freqMap.empty()) {
        char maxChar = 0;
        int maxFreq = 0;
        for (auto& p : freqMap) {
            if (p.second > maxFreq) {
                maxChar = p.first;
                maxFreq = p.second;
            }
        }
        result += string(maxFreq, maxChar);
        freqMap.erase(maxChar);
    }

    return result;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string sortedString = frequencySort(s);
    cout << "Sorted string by frequency: " << sortedString << endl;

    return 0;
}
