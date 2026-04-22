// University Library Management System
/*
Write a System in C++ to manage books and magazines in a University. The university library is
accessible to students, faculty and staff. Each person borrowing a book from the library is
assigned a maximum duration in which the loaner either has to return the book or request an
extension of 10 days at a time. All persons must register with the library before starting to
borrow books. Students are allowed to borrow a maximum of 5 books at a time, while faculty
and staff can borrow up to 10 books.

Books in the library are organized according to the Library of Congress Book classification.
Follow the following article for more information:
https://www.loc.gov/catdir/cpso/lcco/
https://en.wikipedia.org/wiki/Library_of_Congress_Classification

The Library system needs to:
• Manage lending and of books and magazines
• Manage returns of books and magazines
• Review and display Members account and List borrowed books
• List borrowed magazines
• Request an extension to a borrowed books
• Adding and removing Members to the library
• Adding and removing books to the library
• Handle fines of $1.75 per day on late books.
 */


/**
* main.cpp:
 * Program to manage a library system
 *
 *  @authors Noah Shinar and Kami Iwanski
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>

#include "FileHandler.h"

using namespace std;

/**
 * Function main begins with program execution
 *
 * @return The result of program execution
 */

int main() {

    FileHandler createAccount, removeAccount;
    bool validName = false;
    int choice = 0;
    int itemChoiceAdd = 0;
    int itemChoiceBorrow = 0;
    int itemChoiceReturn = 0;
    int typeChoice = 0;
    string name = "";

    while (choice != 9) {
        cout << "1. add new account" << endl; // Done
        cout << "2. remove account" << endl; // Done but confirmation and checking if file exists is broken
        cout << "3. add book or magazine to the library (staff and facility only)" << endl;
        cout << "4. remove book or magazine from the library (staff and facility only)" << endl;
        cout << "5. borrow book or magazine" << endl;
        cout << "6. return book or magazine" << endl;
        cout << "7. view account" << endl;
        cout << "8. request extension" << endl;
        cout << "9. exit program" << endl; // Done

        cout << "choice: ";
        cin >> choice;

        switch (choice) {
            case 1:

                validName = false;
                typeChoice = 0;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (!validName) {

                    cout << "Enter account name (no spaces): ";
                    getline(cin, name);

                    if (name.find(' ') != string::npos || name.empty()) {
                        cout << "Invalid name. Please do not use spaces." << endl;
                    }
                    else if (createAccount.AccountExists(name)) {
                        cout << "Account " << name << " already exists." << endl;
                    }
                    else {
                        validName = true;
                    }
                }

                while (typeChoice != 1 && typeChoice != 2 && typeChoice != 3) {
                    cout << "1. Student" << endl;
                    cout << "2. Facility" << endl;
                    cout << "3. Staff" << endl;
                    cin >> typeChoice;

                    if (typeChoice < 1 || typeChoice > 3) {
                        cout << "Invalid account type selected." << endl; // Loops back to type menu until 1, 2, or 3 is inputted
                    }
                }

                createAccount.RegisterAccount(name, static_cast<AccountTypeEnum>(typeChoice - 1));

                if (typeChoice == 1) {
                    cout << endl << "Account Name: " << name << " Account Type: Student" << endl << endl;
                }
                else if (typeChoice == 2) {
                    cout << endl << "Account Name: " << name << " Account Type: Facility" << endl << endl;
                }
                else if (typeChoice == 3) {
                    cout << endl << "Account Name: " << name << " Account Type: Staff" << endl << endl;
                }

                break;

            case 2:
                validName = false;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                while (!validName) {

                    cout << "Enter account name (no spaces): ";
                    getline(cin, name);

                    if (name.find(' ') != string::npos || name.empty()) {
                        cout << "Invalid name. Please do not use spaces." << endl;
                    }
                    else {
                        validName = true;
                    }
                }

                removeAccount.removeAccount(name);

                break;

            case 3:
                cout << "1. book" << endl << "2. magazine" << endl;
                cin >> itemChoiceAdd;
                if (itemChoiceAdd == 1) {

                }
                else if (itemChoiceAdd == 2) {

                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 4:
                // remove book or magazine from the library (staff and facility only)
                break;

            case 5:
                cout << "1. book" << endl << "2. magazine" << endl;
                cin >> itemChoiceBorrow;
                if (itemChoiceBorrow == 1) {

                }
                else if (itemChoiceBorrow == 2) {

                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 6:
                cout << "1. book" << endl << "2. magazine" << endl;
                cin >> itemChoiceReturn;
                if (itemChoiceReturn == 1) {

                }
                else if (itemChoiceReturn == 2) {

                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 7:
                // view account
                break;

            case 8:
                // request extension
                break;

            case 9:
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}