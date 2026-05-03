//
// Created by noahs on 3/24/26.
//

/**
* Accounts.h:
 * Header file for Account.cpp
 *
 *  @authors Noah Shinar and Kami Iwanski
 */

#ifndef FINALPROJECT_ACCOUNTS_H
#define FINALPROJECT_ACCOUNTS_H

#include <string>
#include <iomanip>

#include "FileHandler.h"
#include "AccountTypeEnum.h"

using namespace std;

class FileHandler;

class Accounts {
    private:
        string accountName;
        AccountTypeEnum type;
        FileHandler fileReference;

    public:
        string borrowedBooks();
        string borrowedMagazines();
        int maxBorrowTime(int inputType);
        string ReviewAccount(int accountNum);
        void displayAccounts();
        string requestExtension(int accountNum);
        int getAccountLine(string name);
};


#endif //FINALPROJECT_ACCOUNTS_H