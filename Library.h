//
// Coded by Kami I. on 4/20/26. Finished by Noah S on 4/21/26.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

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
