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
#include <istream>

#include "Book.h"
#include "Magazine.h"
#include "FileHandler.h"
#include "Library.h"

using namespace std;

/**
 * Function main begins with program execution
 *
 * @return The result of program execution
 */

int main() {

    FileHandler createAccount, removeAccount;
    Book addBook, removeBook, borrowBook;
    Magazine addMagazine, removeMagazine, borrowMagazine;
    Accounts displayAccounts, reviewAccount;
    Library printBooks, printMagazines, returnBookOrMagazine;

    bool validName = false;

    int choice = 0;
    int itemChoiceAdd = 0;
    int itemChoiceBorrow = 0;
    int itemChoiceReturn = 0;
    int itemChoiceRemove = 0;
    int typeChoice = 0;
    int borrowNum = 0;
    int accountNum = 0;

    string name = "";
    string addBookTitle = "";
    string addBookAuthor = "";
    string addBookClassification = "";
    string addMagazineTitle = "";
    string addMagazineAuthor = "";
    string addMagazineClassification = "";
    string titleToReturn = "";

    while (choice != 9) {

        cout << endl;
        cout << "1. add new account" << endl; // Done
        cout << "2. remove account" << endl; // Done
        cout << "3. add book or magazine to the library (staff and facility only)" << endl; // Done
        cout << "4. remove book or magazine from the library (staff and facility only)" << endl; // Done
        cout << "5. borrow book or magazine" << endl; // Done
        cout << "6. return book or magazine" << endl; // Done
        cout << "7. view account" << endl; // display account info: name, type, borrowed books/magazines, due dates
        cout << "8. request extension" << endl; // extend due date to corrisponding account type
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
                    cout << "2. Faculty" << endl;
                    cout << "3. Staff" << endl;
                    cin >> typeChoice;

                    if (typeChoice < 1 || typeChoice > 3) {
                        cout << "Invalid account type selected." << endl; // Loops back to type menu until 1, 2, or 3 is inputted
                    }
                }

                cout << createAccount.RegisterAccount(name, static_cast<AccountTypeEnum>(typeChoice - 1));

                if (typeChoice == 1) {
                    cout << endl << "Account Name: " << name << " Account Type: Student" << endl << endl;
                }
                else if (typeChoice == 2) {
                    cout << endl << "Account Name: " << name << " Account Type: Faculty" << endl << endl;
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

                cout << removeAccount.removeAccount(name);

                break;

            case 3:
                cout << "1. Add book 2. Add magazine: ";
                cin >> itemChoiceAdd;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (itemChoiceAdd == 1) {

                    cout << "Title: ";
                    getline(cin, addBookTitle);

                    cout << "Author: ";
                    getline(cin, addBookAuthor);

                    cout << "Classification: ";
                    getline(cin, addBookClassification);

                    cout << addBook.addBook(addBookTitle, addBookAuthor, addBookClassification) << endl;
                }
                else if (itemChoiceAdd == 2) {
                    cout << "Title: ";
                    getline(cin, addMagazineTitle);

                    cout << "Author: ";
                    getline(cin, addMagazineAuthor);

                    cout << "Classification: ";
                    getline(cin, addMagazineClassification);

                    cout << addMagazine.addMagazine(addMagazineTitle, addMagazineAuthor, addMagazineClassification) << endl;
                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 4:
                cout << "1. Remove book 2. Remove magazine: " << endl;
                cin >> itemChoiceRemove;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (itemChoiceRemove == 1) {
                    cout << "Title: ";
                    getline(cin, addBookTitle);

                    cout << removeBook.removeBook(addBookTitle);
                }
                else if (itemChoiceRemove == 2) {
                    cout << "Title: ";
                    getline(cin, addMagazineTitle);

                    cout << removeMagazine.removeMagazine(addMagazineTitle);
                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 5:
                cout << "Select an account: ";
                displayAccounts.displayAccounts();
                cin >> accountNum;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "1. Borrow book 2. Borrow magazine" << endl;
                cin >> itemChoiceBorrow;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (itemChoiceBorrow == 1) {
                    printBooks.displayBooks();

                    cout << "Enter the number of the book you want to borrow: ";
                    cin >> borrowNum;

                    borrowBook.borrowBook(borrowNum, accountNum);
                }
                else if (itemChoiceBorrow == 2) {
                    printMagazines.displayMagazines();

                    cout << "Enter the number of the magazine you want to borrow: ";
                    cin >> borrowNum;

                    borrowMagazine.borrowMagazine(borrowNum, accountNum);
                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 6:
                cout << "Select an account: ";
                displayAccounts.displayAccounts();
                cin >> accountNum;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Select book/magazine title you want to return: " << endl;
                cout << reviewAccount.ReviewAccount(accountNum) << endl;
                getline(cin, titleToReturn);
                cout << returnBookOrMagazine.returnBookOrMagazine(titleToReturn, accountNum);

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