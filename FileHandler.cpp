//
// Created by noahs on 4/1/26.
//

#include "FileHandler.h"
#include "Accounts.h"
#include <iostream>
#include <fstream>

using namespace std;

string FileHandler::enumToString(AccountTypeEnum type) {
    switch (type) {
        case AccountTypeEnum::STUDENT:
            return "STUDENT";
        case AccountTypeEnum::FACILITY:
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

}