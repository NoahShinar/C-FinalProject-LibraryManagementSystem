//
// Created by noahs on 3/24/26. Updated by Kami I. on 05/03/26.
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
        int maxBorrowTime();
        string ReviewAccount(int accountNum);
        void displayAccounts();
        string requestExtension(string title, int accountNum);
        int getAccountLine(string name);
        double calculateFine(int daysBorrowed);
};


#endif //FINALPROJECT_ACCOUNTS_H