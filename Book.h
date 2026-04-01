//
// Coded by noah s on 3/24/26.
//

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>

using namespace std;

class Book {
    public:
        string title;
        string author;
        string classification; // organizes in alphebetical order and catagories
        bool isBorrowed;
        int yearPublished;

        int dueDay;
        int dueMonth;
        int dueYear;
};


#endif //FINALPROJECT_BOOK_H
