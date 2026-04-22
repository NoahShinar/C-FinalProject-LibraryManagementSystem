//
// Created by noahs on 4/1/26. Updated by Kami I. on 4/22/26.
//

#include "FileHandler.h"
#include "Accounts.h"
#include "Library.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

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
    rename(TEMP_FILE.c_str(), ACCOUNTS_FILE.c_str()); // Rename new file to original name

    if (found) {
        return "Account successfully removed";
    }
    else {
        return "Account not found";
    }
}
