//
// Created by noahs on 4/1/26. Updated by Kami I. on 4/22/26.
//

/**
 * FileHandler.cpp:
 * Class to handle Library.txt and RegisteredAccounts.txt
 *
 * @author Noah S
 * @author Kami I
*/

#include "FileHandler.h"
#include "Accounts.h"
#include "Library.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

/**
 * Function to convert enum type to string
 *
 * @param type enum types STUDENT, FACULTY, STAFF
 * @return AccountTypeEnum type as a string
 */
string FileHandler::enumToString(AccountTypeEnum type) {
    switch (type) {
        case AccountTypeEnum::STUDENT:
            return "STUDENT";
        case AccountTypeEnum::FACULTY:
            return "FACILITY";
        case AccountTypeEnum::STAFF:
            return "STAFF";
        default:
            return "UNKNOWN"; //special case
    }
}

/**
 * Function to check if account exists when trying to create a new account
 *
 * @param name account name
 * @return boolean account exists = true or false
 */
bool FileHandler::AccountExists(string name) {

    ifstream checkFile(ACCOUNTS_FILE);

    if (!checkFile) {
        return false;
    }

    string line;

    while (getline(checkFile, line)) {
        if (line.substr(0, line.find(' ')) == name) {
            checkFile.close();
            return true;
        }
    }

    checkFile.close();
    return false;
}

/**
 * Function to register an account into RegisteredAccounts.txt
 *
 * @param name account name
 * @param type enum types STUDENT, FACULTY, STAFF
 * @return Account registered successfully or Error: Account already exists
 */
string FileHandler::RegisterAccount(string name, AccountTypeEnum type) {

    if (AccountExists(name)) {
        return "Error: Account already exists";
    }

    fstream file(ACCOUNTS_FILE, ios::app);
    if (!file) {
        cerr << "Unable to open file: " << ACCOUNTS_FILE << endl;
        return "Error: Could not open file"; //error code
    }

    file << name << " " << enumToString(type) << endl;
    file.close();

    return "Account registered successfully"; //easy to compute case
}

/**
 * Function to remove an account from RegisteredAccounts.txt
 *
 * @param name account name
 * @return Account successfully removed or Account not found
 */
string FileHandler::removeAccount(string name) {

    ifstream file(ACCOUNTS_FILE);
    ofstream tempFile(TEMP_FILE); // Creates temp file

    if (!file || !tempFile) {
        cerr << "Unable to open file: " << ACCOUNTS_FILE << endl;
        return "Error: Could not open file";
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(name + " ") == 0) {
            found = true;
        }
        else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    // Swap the files
    remove(ACCOUNTS_FILE.c_str()); // Delete old file
    rename(TEMP_FILE.c_str(), ACCOUNTS_FILE.c_str()); // Rename temp file to accounts file name

    if (found) {
        return "Account successfully removed";
    }
    else {
        return "Account not found";
    }
}
