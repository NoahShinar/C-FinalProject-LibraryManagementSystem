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
#include "FileHandler.h"
#include <iostream>
#include <fstream>

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
 * @param accountNum selected account to review
 *
 * @return account type, borrowed books, and magazines
 */
string Accounts::ReviewAccount(int accountNum) {
    int lineCount = 1;
    string line;
    ifstream file(fileReference.ACCOUNTS_FILE);

    if (!file) {
        return "Error opening input file.";
    }

    while (getline(file, line)) {
        if (!line.empty()) {
            if (lineCount == accountNum) {
                file.close();
                return line;
            }
            lineCount++;
        }
    }

    file.close();
    return "Account not found.";
}

/**
 * Function to display all registered accounts
 *
 * return registered accounts list
 */
void Accounts::displayAccounts() {
    int lineCount = 1;
    string line;
    ifstream file(fileReference.ACCOUNTS_FILE);

    if (!file) {
        cerr << "Error opening input file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << endl << "Accounts:" << endl;

    while (getline(file, line)) {
        if (!line.empty()) {
            cout << lineCount << ". " << line << endl;
            lineCount++;
        }
    }

    file.close();
}

/**
 *Function that requests extension
 *
 *return message
 */

string Accounts::requestExtension(string title, int accountNum)
{
    ifstream file(fileReference.ACCOUNTS_FILE);
    ofstream temp(fileReference.TEMP_FILE);

    if (!file || !temp)
    {
        return "Error opening file.";
    }

    string line;
    int lineCount = 1;
    bool found = false;

    while (getline(file, line))
    {
        if (line.find("Borrowed:") != string::npos && line.find(title) != string::npos)
        {
            line += " --> Extension +10 days";
            found = true;
        }
            temp << line << endl;
            lineCount++;
        }

    file.close();
    temp.close();

    remove(fileReference.ACCOUNTS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());

   return found ? "Extension applied successfully." : "Account not found";
}

int Accounts::getAccountLine(string name)
{
    ifstream file(fileReference.ACCOUNTS_FILE);

    string line;
    int lineCount = 1;

    while (getline(file, line))
    {
        if (line.find(name) == 0)
        {
            return lineCount;
        }
        lineCount++;
    }
    return -1;
}
