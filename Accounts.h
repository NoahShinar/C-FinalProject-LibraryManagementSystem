//
// Created by noahs on 3/24/26.
//

#ifndef FINALPROJECT_ACCOUNTS_H
#define FINALPROJECT_ACCOUNTS_H

#include <string>

using namespace std;

class Accounts {
    public:
        string accountName;
        string type; // student, facility, staff

    private:
        string borrowedBooks();
        string borrowedMagazines();
        int maxBorrowTime();
};


#endif //FINALPROJECT_ACCOUNTS_H