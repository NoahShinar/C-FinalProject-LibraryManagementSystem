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
 * Function to set maximum borrow type for each account type and handle fines for late returns
 *
 * @author Kami Iwanski
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
 * Function to check if the user has reached their borrowing limit
 *
 * @author Kami Iwanski
 *
 * @param accountNum The line number of the account
 * @return true if they can borrow more, false if at limit
 */
bool Accounts::canBorrowMore(int accountNum) {
    ifstream file(fileReference.ACCOUNTS_FILE);
    string line;
    int currentLine = 1;

    while (getline(file, line)) {
        if (currentLine == accountNum) {
            int currentCount = 0;
            size_t pos = line.find("Borrowed: ");

            while (pos != string::npos) {
                currentCount++;
                pos = line.find("Borrowed: ", pos + 1);
            }

            int limit = (line.find("Faculty") != string::npos || line.find("Staff") != string::npos) ? 10 : 5;

            file.close();
            return currentCount < limit;
        }
        currentLine++;
    }
    file.close();
    return false;
}

/**
 * Function that decrements duration and applies $1.75 fine if days < 0
 *
 * @author Kami Iwanski
 *
 * @returns updated borrow duration
 */
void Accounts::updateDailyDurations() {
    ifstream file(fileReference.ACCOUNTS_FILE);
    ofstream temp(fileReference.TEMP_FILE);

    string line;
    while (getline(file, line)) {
        size_t durPos = line.find("Duration: ");
        if (durPos != string::npos) {
            size_t endPos = line.find(" days", durPos);
            int start = durPos + 10;

            int days = stoi(line.substr(start, endPos - start));
            days--;
            line.replace(start, endPos - start, to_string(days));

            if (days < 0) {
                double fineAmount = abs(days) * 1.75;
                string fineStr = " | Charges: $" + to_string(fineAmount).substr(0, 4);

                size_t chargePos = line.find(" | Charges: $");
                if (chargePos != string::npos) {
                    line.replace(chargePos, line.length() - chargePos, fineStr);
                }
                else {
                    line += fineStr;
                }
            }
        }
        temp << line << "\n";
    }

    file.close();
    temp.close();
    remove(fileReference.ACCOUNTS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());
}

/**
 *Function to calculate the fine
 *
 *@author Kami Iwanski
 *
 *returns the total fine amount
 */
double Accounts::calculateFine(long borrowTimestamp)
{
    currentTime = time(0);
    secondsBorrowed = currentTime - borrowTimestamp;
    daysBorrowed = secondsBorrowed / 86400;
    limit = maxBorrowTime();

    if (daysBorrowed > limit)
    {
        return (daysBorrowed - limit) * 1.75;
    }
    return 0.0;
}
/**
 * Function to review account info
 *
 * @author Kami Iwanski
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
 * @author Noah Shinar
 *
 * return registered accounts list
 */
void Accounts::displayAccounts() {
    int lineCount = 1;
    string line = "";
    ifstream file(fileReference.ACCOUNTS_FILE);

    if (!file) {
        cerr << "Error opening input file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << endl << "Accounts:" << endl;

    while (getline(file, line)) {
        if (!line.empty()) {
            size_t pos = line.find('|');
            string cleanLine;

            if (pos != string::npos) {
                cleanLine = line.substr(0, pos);
            }
            else {
                cleanLine = line;
            }

            cout << lineCount << ". " << cleanLine << endl;
            lineCount++;
        }
    }

    file.close();
}

/**
 *Function that requests extension
 *
 *@author Kami Iwanski
 *
 *@param title gets title of book
 *@param gets account number
 *
 *@return extension to borrow time
 */

string Accounts::requestExtension(string title, int accountNum) {
    ifstream file(fileReference.ACCOUNTS_FILE);
    ofstream temp(fileReference.TEMP_FILE);

    if (!file.is_open() || !temp.is_open()) return "Error opening file.";

    string line;
    int currentLine = 1;
    bool found = false;

    while (getline(file, line)) {
        if (currentLine == accountNum) {
            // Check if this is the correct book/magazine line
            if (line.find("Borrowed: ") != string::npos && line.find(title) != string::npos) {
                size_t durPos = line.find("Duration: ");
                if (durPos != string::npos) {
                    size_t endPos = line.find(" days", durPos);
                    int start = durPos + 10; // "Duration: " is 10 chars

                    // Extract the current number of days, add 10
                    int currentDays = stoi(line.substr(start, endPos - start));
                    int newDays = currentDays + 10;

                    // Replace only the number in the string
                    line.replace(start, endPos - start, to_string(newDays));
                    found = true;
                }
            }
        }
        temp << line << "\n";
        currentLine++;
    }

    file.close();
    temp.close();

    if (!found) {
        remove(fileReference.TEMP_FILE.c_str());
        return "Item not found or duration format missing.";
    }

    remove(fileReference.ACCOUNTS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());

    return "Extension applied successfully.";
}

/**
 * Helper function that gets account line
 *
 * @author Kami Iwanski
 *
 * @param name account name
 *
 * @return number of account
 */
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
