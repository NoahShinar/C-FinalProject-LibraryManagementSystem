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

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <cctype>

#include "FileHandler.h"

using namespace std;

int main() {

    FileHandler createAccount;
    int choice = 0;
    int itemChoiceAdd = 0;
    int itemChoiceBorrow = 0;
    int itemChoiceReturn = 0;
    int typeChoice = 0;
    string name = "";

    while (choice != 7) {
        cout << "1. add new account" << endl; // Done but need to fix whitespace bug when entering account name
        cout << "2. add book or magazine" << endl;
        cout << "3. borrow book or magazine" << endl;
        cout << "4. return book or magazine" << endl;
        cout << "5. view account" << endl;
        cout << "6. request extension" << endl;
        cout << "7. exit program" << endl; // Done

        cout << "choice: ";
        cin >> choice;

        switch (choice) {
            case 1:

                cout << "Enter account name (no spaces): ";
                cin >> name; // cin causing looping error

                while (typeChoice != 1 && typeChoice != 2 && typeChoice != 3) {
                    cout << "1. Student" << endl;
                    cout << "2. Facility" << endl;
                    cout << "3. Staff" << endl;
                    cin >> typeChoice;

                    if (typeChoice < 1 || typeChoice > 3) {
                        cout << "Invalid account type selected." << endl; // Loop back to type menu until 1, 2, or 3 is inputted
                    }
                }

                createAccount.RegisterAccount(name, static_cast<AccountTypeEnum>(typeChoice - 1));

                break;

            case 2:

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

            case 3:
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

            case 4:
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

            case 5:
                // view account
                break;

            case 6:
                // request extension
                break;

            case 7:
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}