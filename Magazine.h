//
// Created by noahs on 3/24/26.
//

#ifndef FINALPROJECT_MAGAZINE_H
#define FINALPROJECT_MAGAZINE_H

#include <string>

using namespace std;

class Magazine {
    public:
        string title;
        string author;
        bool isBorrowed;
        int yearPublished;

        int dueDay;
        int dueMonth;
        int dueYear;
};


#endif //FINALPROJECT_MAGAZINE_H