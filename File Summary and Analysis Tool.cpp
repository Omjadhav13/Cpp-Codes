
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string path;
    cout << "Enter the file path: ";
    getline(cin, path);

    ifstream file(path);
    if (!file) {
        cout << "Error: File could not be opened.\n";
        return 1;
    }

    int ccount = 0;   // alphabets
    int dcount = 0;   // digits
    int scount = 0;   // special chars
    int lcount = 0;   // lines
    int spacecount = 0; // spaces

    char c;
    while (file.get(c)) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            ccount++;
        }
        else if (c >= '0' && c <= '9') {
            dcount++;
        }
        else if (c == ' ') {
            spacecount++;
        }
        else if (c == '\n') {
            lcount++;
        }
        else {
            scount++;
        }
    }

    int wcount = spacecount + 1;  // Rough estimate

    cout << "Character count: " << ccount << endl;
    cout << "Digit count: " << dcount << endl;
    cout << "Space count: " << spacecount << endl;
    cout << "Line count: " << lcount << endl;
    cout << "Word count: " << wcount << endl;

    file.close();
}