//
// Coded by noahs on 4/1/26.
//

/**
 * FileHandler.h:
 * Header file for FileHandler.cpp
 *
 * @author Noah S
 * @author Kami I
*/

#ifndef FINALPROJECT_FILEHANDLER_H
#define FINALPROJECT_FILEHANDLER_H

#include <string>
#include "Accounts.h"

using namespace std;

class FileHandler {
    friend class Library;
    private:
        const string ACCOUNTS_FILE = "/home/noahs/CLionProjects/FinalProject/RegisteredAccounts.txt";
        const string LIBRARY_FILE = "/home/noahs/CLionProjects/FinalProject/Library.txt";
        const string TEMP_FILE = "/home/noahs/CLionProjects/FinalProject/tempFile.txt";

    public:
        string enumToString(AccountTypeEnum type);
        bool AccountExists(string name);
        string RegisterAccount(string name, AccountTypeEnum type);
        string removeAccount(string name);
};


#endif //FINALPROJECT_FILEHANDLER_H
