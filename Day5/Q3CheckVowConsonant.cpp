#include <iostream>
#include <string>
using namespace std;

void countVowelsAndConsonants(const string& str, int& vowelCount, int& consonantCount) {
    vowelCount = 0;
    consonantCount = 0;

    for (char c : str) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelCount++;
        } else if (c >= 'a' && c <= 'z') {
            consonantCount++;
        }
    }
}

int main() {
    string inputString;
    int vowels = 0, consonants = 0;

    cout << "Enter a string: ";
    cin >> inputString;

    countVowelsAndConsonants(inputString, vowels, consonants);

    cout << "Number of vowels: " << vowels << endl;
    cout << "Number of consonants: " << consonants << endl;

    return 0;
}
