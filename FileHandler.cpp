//
// Created by noahs on 4/1/26.
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
            return "UNKNOWN";
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
        return "Error: Could not open file";
    }

    file << name << " " << enumToString(type) << endl;
    file.close();

    return "Account registered successfully";
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
string FileHandler::getBooks() {

    ifstream file(LIBRARY_FILE);

    if (!file) {
        cerr << "Unable to open file: " << LIBRARY_FILE << endl;
        return "Error: Could not open file";
    }

    string input;
    int lineCount = 0;

    while (getline(file, input)) {
        lineCount++;

        if (lineCount >= 0 && lineCount <= 50) {
            cout << "Books: " << input << endl;
        }
        else {
            break;
        }
    }

    file.close();
}
string FileHandler::getMagazines() {

    ifstream file(LIBRARY_FILE);

    if (!file) {
        return "Error: Could not open file";
    }

    string input;
    int lineCount = 0;
    string result = "Magazines:\n";

    while (getline(file, input)) {
        lineCount++;

        if (lineCount >= 51 && lineCount <= 100) {
            cout << "Magazines: " << input << endl;
        }
    }

    file.close();
    return result;
}
string addBook(string name, AccountTypeEnum type) {

}
string addMagazine(string name, AccountTypeEnum type) {

}