//
// Created by noahs on 4/1/26.
//

#include "FileHandler.h"
#include "Accounts.h"
#include "Library.h"
#include <iostream>
#include <fstream>

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

string FileHandler::RegisterAccount(string name, AccountTypeEnum type) {

    fstream file(ACCOUNTS_FILE, ios::app);

    if (!file) {
        cerr << "Unable to open file: " << ACCOUNTS_FILE << endl;
        return "Error: Could not open file";
    }

    ifstream checkFile(ACCOUNTS_FILE);
    string line;

    while (getline(checkFile, line)) {
        if (line.find(name) != string::npos) {
            checkFile.close();
            return "Error: Account already exists";
        }
    }
    checkFile.close();

    file << name << " " << enumToString(type) << endl;
    file.close();

    return "Account registered successfully";
}
string FileHandler::libraryFile() {

     ifstream file(LIBRARY_FILE);

    if (!file) {
        cerr << "Unable to open file: " << LIBRARY_FILE << endl;
        return "Error: Could not open file";
    }

    string input;
    int lineCount = 0;

    while (getline(file, input)) {
        lineCount++;

        if (lineCount <= 50 && lineCount >= 0) {
            cout << "Books: " << input << endl;
        }
        else if (lineCount >= 51 && lineCount <= 100) {
            cout << "Magazines: " << input << endl;
        }
        else {
            break;
        }
    }

    file.close();
}