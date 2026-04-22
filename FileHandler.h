//
// Coded by noahs on 4/1/26.
//

#ifndef FINALPROJECT_FILEHANDLER_H
#define FINALPROJECT_FILEHANDLER_H

#include <string>
#include "Accounts.h"

using namespace std;

class FileHandler {
    private:
        const string ACCOUNTS_FILE = "/home/noahs/CLionProjects/FinalProject/RegisteredAccounts.txt";
        const string LIBRARY_FILE = "/home/noahs/CLionProjects/FinalProject/Library.txt";
        const string TEMP_FILE = "/home/noahs/CLionProjects/FinalProject/tempFile.txt";

    public:
        string enumToString(AccountTypeEnum type);
        bool AccountExists(string name);
        string RegisterAccount(string name, AccountTypeEnum type);
        string removeAccount(string name);
        string getBooks();
        string getMagazines();
        string addBook(string name, AccountTypeEnum type);
        string addMagazine(string name, AccountTypeEnum type);
};


#endif //FINALPROJECT_FILEHANDLER_H
