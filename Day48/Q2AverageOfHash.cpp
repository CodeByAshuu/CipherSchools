#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

map<string, double> getAverageScores(const map<string, vector<int>>& scoresByStudent) {
    map<string, double> averages;

    for (const auto& entry : scoresByStudent) {
        const string& name = entry.first;
        const vector<int>& scores = entry.second;

        double average = 0;
        if (!scores.empty()) {
            average = static_cast<double>(accumulate(scores.begin(), scores.end(), 0)) / scores.size();
        }

        averages[name] = average;
    }

    return averages;
}

void displayAverages(const map<string, double>& averages) {
    cout << "{ ";
    for (const auto& entry : averages) {
        cout << "\"" << entry.first << "\": " << entry.second << ", ";
    }
    cout << "}" << endl;
}

int main() {
    map<string, vector<int>> students = {
        {"Alice", {80, 90, 100}},
        {"Bob", {70, 75, 80}},
        {"Charlie", {60}}
    };

    map<string, double> averages = getAverageScores(students);
    cout << "Average Scores: ";
    displayAverages(averages);

    return 0;
}
