//
// Coded by Kami I. on 4/20/26.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "Book.h"
#include "Magazine.h"
#include "FileHandler.h"
#include "Accounts.h"
#include <string>

using namespace std;

class Library {
    private:
        FileHandler fileReference;
        string input = "";
        int lineCount = 0;

    public:
        string listBooks();
        string listMagazines();
};


#endif //FINALPROJECT_LIBRARY_H
