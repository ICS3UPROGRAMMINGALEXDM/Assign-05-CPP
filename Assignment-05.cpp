// Copyright (c) 2022 Alex De Meo All rights reserved
//
// Created By: Alex De Meo
// Date: 04s//22
// Description: This assignment I will be making a pogram that either
// calculates the acceleration given the force and mass or b) calculates the
// hypotenuse of a right angle triangle given the base and height or c)
// calculates teh average speed of a trip given distance and time
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stof;



// This function calculates the acceleration with the given mass and force
float calcAcc(float force, float mass) {
    float acc = force / mass;
    // returning to where the function was called
    return acc;
}



// This function calulates teh hypotenuse with the inputted base and height
float calcHyp(float base, float height) {
    // calculation
    float hypSqr = pow(base, 2) + pow(height, 2);
    float hyp = sqrt(hypSqr);

    // returns to where the function was called
    return hyp;
}


// This function calculates the average speed given the distance and time
float calcSpeed(float cTime, float distance) {
    float speed = distance / cTime;

    // returns to where the function was called
    return speed;
}


// This is the function that gets the unit and measurements and will later call
// another function to make the calculations for the hypotenuse
void hypotenuse() {
    bool unitFailure = true;
    bool measureFailure = false;
    // allows to re-enter the unit if it was incorrectly iputted the first time
    while (unitFailure) {
        string unit;
        cout << "Which of the following units would you like to use? " <<
        "(cm, m, km, mm): ";
        cin >> unit;

        // Ensuring a valid unit
        if (unit == "cm" || unit == "mm" || unit == "m" || unit == "km") {
            measureFailure = true;
        } else {
            cout << "I don't understand, try again." << endl;
        }
        // allos to re-enter measurements if they were incorrectly inputted
        while (measureFailure) {
            string uBase, uHeight;
            cout << "What is the base length of your triangle: ";
            cin >> uBase;

            cout << "What is the height of your triangle: ";
            cin >> uHeight;

            try {
                // converting to float
                float baseFlt = stof(uBase);
                float heightFlt = stof(uHeight);

                if (baseFlt > 0 && heightFlt > 0) {
                    measureFailure = false;
                    unitFailure = false;
                    // calling the function that will calculate the hypotenuse
                    float answer1 = calcHyp(baseFlt, heightFlt);
                    // display results
                    cout << "The hypotenuse of your triangle is " << answer1 <<
                    std::fixed << std::setprecision(2) <<
                    std::setfill('0') << " " << unit << endl;
                } else {
                    cout << "Numbers must be positive" << endl;
                }
            } catch (...) {
                cout << "Numbers entered weren't valid numbers" << endl;
            }
        }
    }
}


// This is the function that gets the unit and measurements and will later call
// another function to make the calculations for the acceleration
void acceleration(string accUnit = "m/s^2") {
    bool measureFailure2 = true;

    while (measureFailure2) {
        // getting user input
        string uForce, uMass;
        cout << "Input the force (Already set to Newtons): ";
        cin >> uForce;

        cout << "Enter the mass (Already set to kg): ";
        cin >> uMass;

        try {
            // converting to float
            float forceFlt = stof(uForce);
            float massFlt = stof(uMass);

            // Ensuring mass is positive
            if (massFlt > 0) {
                measureFailure2 = false;
                // calling the function that will calculate the acceration
                float answer2 = calcAcc(forceFlt, massFlt);

                cout << "The resulting acceleration is " << answer2 <<
                std::fixed << std::setprecision(2) << std::setfill('0') <<
                accUnit << endl;
            } else {
                cout << "Thr inputted mass can't be negative." << endl;
            }
        } catch (...) {
            cout << "Numbers entered weren't real numbers" << endl;
        }
    }
}


// This is the function that gets the unit and measurements and will later call
// another function to make the calculations for the average speed
void speed() {
    bool unitFailure2 = true;
    bool measureFailure3 = false;

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
            measureFailure3 = true;
        } else {
            cout << "Unit(s) enetered were invalid" << endl;
        }
        // allows for the measurements to be re-entered if they were invalid
        while (measureFailure3) {
            // getting user input
            string uTime, uDistance;
            cout << "Enter how long the trip took: ";
            cin >> uTime;

            cout << "Enter the distance traveled: ";
            cin >> uDistance;

            try {
                // converting to float
                float timeFlt = stof(uTime);
                float distanceFlt = stof(uDistance);

                // ensuring positive numbers
                if (timeFlt > 0 && distanceFlt > 0) {
                    unitFailure2 = false;
                    measureFailure3 = false;
                    // calls the function that'll calculate the average speed
                    float answer3 = calcSpeed(timeFlt, distanceFlt);
                    // display results
                    cout << "The average speed was " << answer3 << std::fixed <<
                    std::setprecision(2) << std::setfill('0') << " " <<
                    distanceUnit << "/" << timeUnit << endl;
                } else {
                    cout << "The inputted numbers must be positive" << endl;
                }
            } catch (...) {
                cout << "Inputted numbers weren't real numbers" << endl;
            }
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
        cout << "Choose a calculator to use: " << endl <<
        "1 - Hypotenuse given base and height of a right angled triangle" <<
        endl << "2 - Acceleration given mass and force" << endl <<
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
            cout << "I don't understand, Please try again.";
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
