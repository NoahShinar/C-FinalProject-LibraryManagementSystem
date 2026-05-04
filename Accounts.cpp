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
#include <ctime>

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
 * @return maximum amount of days each account has to borrow books and magazines and handle late fees
 */
int Accounts::maxBorrowTime() {
    // Students are allowed to borrow a maximum of 5 books at a time, while faculty and staff can borrow up to 10 books.
    // Handle fines of $1.75 per day on late books.

    if (type == AccountTypeEnum::STUDENT)
    {
        return 30; //days loaned
    }
    else if (type == AccountTypeEnum::FACULTY || type == AccountTypeEnum::STAFF)
    {
        return 60; //days loaned
    }
    else {
        return 30; //default
    }
}
/**
 *Function to calculate the fine
 *
 *returns the total fine amount
 */
double Accounts::calculateFine(long borrowTimestamp)
{
    time_t currentTime = time(0);
    long secondsBorrowed = currentTime - borrowTimestamp;

    int daysBorrowed = secondsBorrowed / 86400;

    int limit = maxBorrowTime();

    if (daysBorrowed > limit)
    {
        return (daysBorrowed - limit) * 1.75;
    }
    return 0.0;
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

    if (!file) return "Error opening input file.";

    while (getline(file, line)) {
        if (!line.empty() && lineCount == accountNum) {
            file.close();

            size_t tsPos = line.find("Timestamp: ");
            if (tsPos != string::npos) {
                long ts = stol(line.substr(tsPos + 3));
                double fine = calculateFine(ts);

                if (fine > 0)
                {
                    return line + " - Overdue Fine: $" + to_string(fine).substr(0, 4);
                }
            }
            return line + " - No current fines";
        }
        lineCount++;
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

    if (!file || !temp) return "Error opening file.";

    string line;
    int currentLine = 1; // Track which account we are looking at
    bool found = false;

    while (getline(file, line))
    {
        // Only attempt extension if the line number matches the selected accountNum
        if (currentLine == accountNum)
        {
            if (line.find("Borrowed: ") != string::npos && line.find(title) != string::npos)
            {
                line += " --> Extension +10 days";
                found = true;
            }
        }
        temp << line << endl;
        currentLine++;
    }

    file.close();
    temp.close();

    if (!found) {
        temp.close();
        remove(fileReference.TEMP_FILE.c_str());
        return "Item not found for this account.";
    }

    remove(fileReference.ACCOUNTS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());

    return "Extension applied successfully.";
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
