#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    int vowelCount = 0, consonantCount = 0;

    // Take input from user
    cout << "Enter a string: ";
    getline(cin, input);

    // Convert input to lowercase for case-insensitive comparison
    for (char &ch : input) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32; // Convert to lowercase
        }
    }

    // Count vowels and consonants
    for (char ch : input) {
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowelCount++;
            } else {
                consonantCount++;
            }
        }
        // Ignore non-alphabetic characters (spaces, symbols)
    }

    // Display results
    cout << "Vowels: " << vowelCount << endl;
    cout << "Consonants: " << consonantCount << endl;

    return 0;
}
