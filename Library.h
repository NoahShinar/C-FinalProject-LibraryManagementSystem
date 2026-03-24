//
// Created by noahs on 3/24/26.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "Book.h"
#include "Magazine.h"
#include <string>

using namespace std;

class Library {
    private:
        string listBooks();
        string listMagazines();
        string listMembers();
};


#endif //FINALPROJECT_LIBRARY_H