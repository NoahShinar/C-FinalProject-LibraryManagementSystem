//
// Created by noahs on 3/24/26.
//

#ifndef FINALPROJECT_ACCOUNTS_H
#define FINALPROJECT_ACCOUNTS_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <utility>

#include "AccountTypeEnum.h"

using namespace std;

class Accounts {
    private:
        string accountName;
        AccountTypeEnum type;

    public:
        string borrowedBooks();
        string borrowedMagazines();
        int maxBorrowTime(int inputType);
};


#endif //FINALPROJECT_ACCOUNTS_H