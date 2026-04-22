//
// Coded by Kami I. on 3/30/36. Updated by Noah S on 4/21/26.
//

/**
* Accounts.cpp:
 * Program to manage registered account info
 *
 *  @authors Noah Shinar and Kami Iwanski
 */

#include "Accounts.h"

using namespace std;

/**
 * Function to show borrowed books
 *
 * @return borrowed books
 */
string Accounts::borrowedBooks() {
    return "No books stored";
}

/**
 * Function to show borrowed magazines
 *
 * @return borrowed magazines
 */
string Accounts::borrowedMagazines() {
    return "No magazines stored";
}

/**
 * Function to set maximum borrow type for each account type and handle fines for late returns
 *
 * @param inputType account type
 * @return maximum amount of days each account has to borrow books and magazines and handle late fees
 */
int Accounts::maxBorrowTime(int inputType) {
    // Students are allowed to borrow a maximum of 5 books at a time, while faculty and staff can borrow up to 10 books.
    // Handle fines of $1.75 per day on late books.
    type = static_cast<AccountTypeEnum>(inputType);

    if (type == AccountTypeEnum::STUDENT) {
        return 30; //days loaned
    }
    else if (type == AccountTypeEnum::FACULTY || type == AccountTypeEnum::STAFF) {
        return 60; //days loaned
    }
    else {
        return 30; //default
    }
}

/**
 * Function to review account info
 *
 * @return account type, borrowed books, and magazines
 */
string Accounts::ReviewAccount() {
    string accountInfo = "Account Type: ";

    if (type == AccountTypeEnum::STUDENT) {
        accountInfo += "Student";
    }
    else if (type == AccountTypeEnum::FACULTY) {
        accountInfo += "Faculty";
    }
    else if (type == AccountTypeEnum::STAFF) {
        accountInfo += "Staff";
    }
    else {
        accountInfo += "Unknown";
    }

    accountInfo += "\nBooks: " + borrowedBooks();
    accountInfo += "\nMagazines: " + borrowedMagazines();

    return accountInfo;
}

