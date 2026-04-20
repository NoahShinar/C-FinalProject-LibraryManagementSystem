//
// Coded by Kami I. on 4/20/26.
//

#ifndef FINALPROJECT_LIBRARY_H
#define FINALPROJECT_LIBRARY_H

#include "Book.h"
#include "Magazine.h"
#include <string>

using namespace std;

class Library {
public:
        string listBooks();
        string listMagazines();
        string listMembers();
};


#endif //FINALPROJECT_LIBRARY_H
