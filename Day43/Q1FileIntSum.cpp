#include <iostream>
#include <fstream>
#include <exception>
#include <string>
using namespace std;

class NonIntegerDataException : public exception {
public:
    const char* what() const throw() {
        return "Error: Non-integer data found in the file.";
    }
};

int main() {
    string filePath;
    cout << "Enter the file path: ";
    cin >> filePath;

    ifstream inputFile;
    int sum = 0;

    try {
      //dekhlo ab file path apne hisab se
        inputFile.open(filePath);
        if (!inputFile.is_open()) {
            throw ios_base::failure("Error: Could not open the file.");
        }

        try {
            int number;
            while (inputFile >> number) {
                sum += number;
            }
            
            if (inputFile.fail() && !inputFile.eof()) {
                throw NonIntegerDataException();
            }
            
            cout << "The sum of integers in the file is: " << sum << endl;
        }
        catch (const NonIntegerDataException& e) {
            cout << e.what() << endl;
        }

        inputFile.close();
    }
    catch (const ios_base::failure& e) {
        cout << e.what() << endl;
    }

    return 0;
}
