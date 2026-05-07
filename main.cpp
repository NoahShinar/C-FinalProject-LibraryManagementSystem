/**
 * main.cpp:
 * Program to manage a library system
 *
 * @authors Noah Shinar and Kami Iwanski
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

    FileHandler fileHandler;
    Book book;
    Magazine magazine;
    Accounts accounts;
    Library library;

    bool validName = false;

    int choice = 0;
    int itemChoiceAdd = 0;
    int itemChoiceBorrow = 0;
    int itemChoiceRemove = 0;
    int typeChoice = 0;
    int borrowNum = 0;
    int accountNum = 0;
    int daysBorrowed = 0;

    string name = "";
    string addBookTitle = "";
    string addBookAuthor = "";
    string addBookClassification = "";
    string addMagazineTitle = "";
    string addMagazineAuthor = "";
    string addMagazineClassification = "";
    string titleToReturn = "";
    string titleToExtend = "";

    while (choice != 9) {

        accounts.updateDailyDurations();

        library.printMenu();

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
                    else if (fileHandler.AccountExists(name)) {
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

                cout << fileHandler.RegisterAccount(name, static_cast<AccountTypeEnum>(typeChoice - 1));

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

                    accounts.displayAccounts();
                    cout << "Enter account name (no spaces): ";
                    getline(cin, name);

                    if (name.find(' ') != string::npos || name.empty()) {
                        cout << "Invalid name. Please do not use spaces." << endl;
                    }
                    else {
                        validName = true;
                    }
                }

                cout << fileHandler.removeAccount(name);

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

                    cout << book.addBook(addBookTitle, addBookAuthor, addBookClassification) << endl;
                }
                else if (itemChoiceAdd == 2) {
                    cout << "Title: ";
                    getline(cin, addMagazineTitle);

                    cout << "Author: ";
                    getline(cin, addMagazineAuthor);

                    cout << "Classification: ";
                    getline(cin, addMagazineClassification);

                    cout << magazine.addMagazine(addMagazineTitle, addMagazineAuthor, addMagazineClassification) << endl;
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

                    library.displayBooks();
                    cout << "Title: ";
                    getline(cin, addBookTitle);

                    cout << book.removeBook(addBookTitle);
                }
                else if (itemChoiceRemove == 2) {

                    library.displayMagazines();
                    cout << "Title: ";
                    getline(cin, addMagazineTitle);

                    cout << magazine.removeMagazine(addMagazineTitle);
                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 5:
                cout << "Select an account: ";
                accounts.displayAccounts();
                cin >> accountNum;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "1. Borrow book 2. Borrow magazine" << endl;
                cin >> itemChoiceBorrow;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (itemChoiceBorrow == 1) {
                    library.displayBooks();

                    cout << "Enter the number of the book you want to borrow: ";
                    cin >> borrowNum;

                    book.borrowBook(borrowNum, accountNum);
                }
                else if (itemChoiceBorrow == 2) {
                    library.displayMagazines();

                    cout << "Enter the number of the magazine you want to borrow: ";
                    cin >> borrowNum;

                    magazine.borrowMagazine(borrowNum, accountNum);
                }
                else {
                    cout << "Invalid choice" << endl;
                }
                break;

            case 6:
                cout << "Select an account: ";
                accounts.displayAccounts();
                cin >> accountNum;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "--- Current Account Status ---" << endl;
                cout << accounts.ReviewAccount(accountNum) << endl;
                cout << "------------------" << endl;

                cout << "Select book or magazine to return: " << endl;
                getline(cin, titleToReturn);

                cout << "Enter days borrowed: ";
                cin >> daysBorrowed;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << library.returnBookOrMagazine(titleToReturn, accountNum) << endl;
                break;

            case 7:
                cout << "Select an account: ";
                accounts.displayAccounts();
                cin >> accountNum;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << accounts.ReviewAccount(accountNum) << endl;

                break;

            case 8:
                cout << "Select an account: ";
                accounts.displayAccounts();
                cin >> accountNum;

                cout << accounts.ReviewAccount(accountNum) << endl;

                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Enter book/magazine to extend: ";
                getline(cin, titleToExtend);

                cout << accounts.requestExtension(titleToExtend, accountNum) << endl;

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