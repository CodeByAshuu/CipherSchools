#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> getFrequencyMap(const string& input) {
    map<char, int> frequencyMap;

    for (char c : input) {
        frequencyMap[c]++;
    }

    return frequencyMap;
}

void printFrequencyMap(const map<char, int>& frequencyMap) {
    for (const auto& pair : frequencyMap) {
        cout << "'" << pair.first << "': " << pair.second << ", ";
    }
    cout << endl;
}

int main() {
    string input1 = "HelloWorld";
    map<char, int> result1 = getFrequencyMap(input1);
    cout << "Frequency Map for \"" << input1 << "\": { ";
    printFrequencyMap(result1);
    cout << "}" << endl;

    string input2 = "C++STL";
    map<char, int> result2 = getFrequencyMap(input2);
    cout << "Frequency Map for \"" << input2 << "\": { ";
    printFrequencyMap(result2);
    cout << "}" << endl;

    return 0;
}
