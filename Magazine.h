//
// Coded by noah s + Kami I. on 3/24/26 and 4/20/26.
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

        Magazine();
};


#endif //FINALPROJECT_MAGAZINE_H
