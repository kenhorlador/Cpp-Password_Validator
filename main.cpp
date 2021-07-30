#include <iostream>
#include <string>
#include <cctype>


/*
You may use namespace std here
but it will consume a lot of time executing
those functions that are not included in
this program. So I just picked some funcs
that are used in this program
*/
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::getline;



bool passwordValidator(string pass) {
    /*
    Variables or flags to determine whether the
    string contains, upper case, lower case characters, and
    special characters
    */
    bool containsUpperCaseLetter = false,
         containsLowerCaseLetter = false,
         containsSpecialCharacter = false,
         containsNumber = false;

    /*
    Checks if the password is at least 6 digits long, returns false if not
    */
    if (pass.length() < 6) {
        cout << "Password should be atleast 6 digits long\n";
        return false;
    }

    /*
    Loops through every character of the password and
    determines whether it has upper case, lower case character/s,
    and/or special characters, returns true if it does have
    */
    for (int i = 0; i < pass.length(); i++) {
        if (isupper(pass[i])) {
            containsUpperCaseLetter = true; // Uppercase letter
        }
        else if (islower(pass[i])) {
            containsLowerCaseLetter = true; // Lowercase letter
        }
        else if (isdigit(pass[i])) {
            containsNumber = true; // Number
        }
        else {
            containsSpecialCharacter = true;
        }
    }
    if (!containsLowerCaseLetter) {
        cout << "The password should contain a lower case character\n";
        return false;
    }
    else if (!containsUpperCaseLetter) {
        cout << "The password should contain an upper case character\n";
        return false;
    }
    else if (!containsSpecialCharacter) {
        cout << "The password should contain at least one special character\n";
        return false;
    }
    else if (!containsNumber) {
        cout << "The password should contain at least one digit or number\n";
    }
    return true;
}


int main()
{
    string password;

    // Ask for a password value then store it in a variable
    cout << "Enter Password: ";
    getline(cin, password);

    if (passwordValidator(password)) {
        cout << "This password is valid\n";
    }
    else {
        cout << "This password is invalid\n";
    }
    return 0;
}


