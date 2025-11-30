#include <iostream>
#include <vector>
#include <cctype>
#include <conio.h> // For getch() function
using namespace std;

int main() {
    string password;
    char ch;

    cout << "Enter Password: ";

    // Get password without displaying it
    while ((ch = _getch()) != '\r') { // '\r' is the carriage return (Enter key)
        password.push_back(ch);
        cout << '*'; // Display asterisk for each character typed
    }
    cout << endl;

    // Check if the password is too short
    if (password.size() < 8) {
        cout << "Password is too short" << endl;
        cout << "Not Enough Value" << endl;
        return 0; // Exit early as password does not meet length requirement
    }

    // Variables to track the different types of characters
    bool upper = false, lower = false, special = false, digit = false;

    // Iterate through each character in the password to check its type
    for (char ch : password) {
        if (isupper(ch)) {
            upper = true;
        } else if (islower(ch)) {
            lower = true;
        } else if (isdigit(ch)) {
            digit = true;
        } else if (ispunct(ch)) {
            special = true;
        }
    }

    // Check if all conditions are satisfied
    if (upper && lower && special && digit) {
        cout << "Password is strong!" << endl;
    } else {
        cout << "Password is not strong enough" << endl;
        if (!upper) cout << "Needs at least one uppercase letter." << endl;
        if (!lower) cout << "Needs at least one lowercase letter." << endl;
        if (!digit) cout << "Needs at least one digit." << endl;
        if (!special) cout << "Needs at least one special character." << endl;
    }

    return 0;
}
