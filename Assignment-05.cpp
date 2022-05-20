#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::stof

void speed() {
    bool unitFailure2 = true;

    // Allows to re-enter the unit if it was invalid
    while (unitFailure2) {
        string timeUnit, distanceUnit;
        cout << "Enter the unit of time (s, hr, min): ";
        cin >> timeUnit;

        cout << "Enter the unit of distance(m, km): ";
        cin >> distanceUnit;

        // Ensuring that all units were valid
        if ((distanceUnit == "m" || distanceUnit == "km") && (timeUnit == "s"
        || timeUnit == "min" || timeUnit == "hr")) {
            // allows for the next part of the function to continue
            bool measureFailure3 = true;
        }
    }
}


int main() {
    bool restartLoop = true;
    // loop allows for the user to choose a new program once the previous
    // calculations are complete
    while (restartLoop) {
        bool retryLoop = true;
        // getting user's choice for the program
        string choice;
        cout << "Choose a calculator to use: " << endl
        "1 - Hypotenuse given base and height of a right angled triangle" <<
        "2 - Acceleration given mass and force" << endl
        "3 - Average Speed given distance and time" << endl << endl <<
        "Selection: ";
        cin >> choice;
        // calls whichever function was chosen
        if (choice == "1") {
            hypotenuse();
        } else if (choice == "2") {
            acceleration();
        } else if (choice == "3") {
            speed();
        } else {
            cout << "I don't understand, Please try again."
        }

        while (retryLoop) {
            string choice2;
            cout << "Would you like to play again? (y/n): ";
            cin >> choice2;

            // this is what decides whether or not to rum the program again
            if (choice2 == "y") {
                retryLoop = false;
            } else if (choice2 == "n") {
                retryLoop = false;
                restartLoop = false;
            } else {
                cout << "I don't understand, try again!" << endl;
            }
        }
    }
}