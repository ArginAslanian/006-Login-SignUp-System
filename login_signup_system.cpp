/**
 * Programmer: Argin Aslanian
 * Purpose: This program is a simple login/signup system that
 *          checks for password validation for a signed up user.
 *
 * Class Name: User
 *
 * Member functions:
 *      login()
 *          This function will validate the password entered for that username and
 *              will either log the user in, or display "Wrong password!", or display
 *              "Sign up First! " if that username was not found in the map.
 *
 *      signUp()
 *          This function will sign the user up using the username and the password
 *              entered, by inserting it to the users map.
 *
 *      seeUsers()
 *          This function will display the list of signed up users.
 */

#include <iostream>
#include <map>
#include <limits>
using namespace std;

//Declare user's choice validation function.
int validateChoice();

class User {
    //Declare variables and users map.
    string username, password;
    map<string, string> users = {};

public:
    void login();
    void signUp();
    void seeUsers();
};

int main() {

    User user;
    int choice;

    //As long as the user does not quit by pressing 4, keep going.
    do {
        //Get user's menu selection.
        cout << "1. Login " << endl << "2. Sign Up " << endl << "3. See Users " << endl << "4. Quit " << endl;
        cout << "CHOOSE FROM THE SELECTION MENU: " << endl;
        choice = validateChoice();

        switch (choice) {

            case 1:
                user.login();
                break;

            case 2:
                user.signUp();
                break;

            case 3:
                user.seeUsers();
                break;

            case 4:
                cout << "GoodBye!" << endl;
                break;

            default:
                break;

        }

    } while (choice != 4);

    return 0;
}

void User::login() {

    //Get username and password.
    cout << "Username: (NO SPACES)";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    //Check if the username exists in the map or not.
    if (users.count(username) != 0) {

        //If it exists, then compare the password that was entered.
        if (users[username] == password) {
            cout << "Logged In! " << endl;
        } else {
            cout << "Wrong password! " << endl;
        }

    } else {
        //If the username did not exist, prompt the user to sign up.
        cout << "Sign up First! " << endl;
    }

}

void User::signUp() {

    //Get username and password.
    cout << "Username: (NO SPACES)";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    //Check if that username is already taken or not.
    if (users.count(username) == 0) {

        //If the username was not taken, sign the user up.
        users.insert({username, password});
        cout << "Signed up! " << endl;
    } else {
        //If the username was taken, display appropriate message.
        cout << "Username already taken " << endl;
    }

}

//Display the usernames of all the signed up users.
void User::seeUsers() {

    //Check to see if the map is empty.
    if (!users.empty()) {

        //If map is not empty, display the usernames of the users.
        cout << "Usernames: " << endl;
        for (auto it = users.cbegin(); it != users.cend(); it++) {
            cout << it->first <<  endl;
        }

    } else {

        //If map is empty, show the appropriate message.
        cout << "There are no users to display! " << endl;

    }

}

//Validate user's menu selection.
int validateChoice() {
    int retVal;

    //Input has to be numeric.
    while (!(cin >> retVal)) {
        cout << "Enter numeric values 1 - 4: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    //Input has to be between 1 and 4.
    if (retVal < 1 || retVal > 4) {
        cout << "Enter numeric values 1 - 4: ";
        retVal = validateChoice();
    }

    return retVal;
}