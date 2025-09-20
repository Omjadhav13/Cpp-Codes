#include <iostream>
using namespace std;

int main() {
    int n;

    // Take user input for the side length
    cout << "Enter the side length of the square: ";
    cin >> n;

    // Validate input (optional)
    if (n < 1) {
        cout << "Invalid size. Must be greater than 0." << endl;
        return 1;
    }

    // Generate hollow square pattern
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Print '*' on the borders
            if (i == 1 || i == n || j == 1 || j == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;  
    }

    return 0;
}
