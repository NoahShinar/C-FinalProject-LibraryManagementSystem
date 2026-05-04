//
// Coded by noahs on 4/1/26. Edited by Kami I. on 5/03/26.
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
#include "AccountTypeEnum.h"

using namespace std;

class FileHandler {
    friend class Library;
    friend class Book;
    friend class Magazine;
    friend class Accounts;

    private:
        const string ACCOUNTS_FILE = "/Users/kamiiwanski/home/RegisteredAccounts.txt";
        const string BOOKS_FILE = "/Users/kamiiwanski/home/FinalProject/Books.txt";
        const string MAGAZINES_FILE = "/Users/kamiiwanski/home/Magazines.txt";
        const string TEMP_FILE = "/Users/kamiiwanski/home/tempFile.txt";

        // const string ACCOUNTS_FILE = "RegisteredAccounts.txt";
        // const string BOOKS_FILE = "Books.txt";
        // const string MAGAZINES_FILE = "Magazines.txt";
        // const string TEMP_FILE = "tempFile.txt";

    public:
        string enumToString(AccountTypeEnum type);
        bool AccountExists(string name);
        string RegisterAccount(string name, AccountTypeEnum type);
        string removeAccount(string name);
};


#endif //FINALPROJECT_FILEHANDLER_H
