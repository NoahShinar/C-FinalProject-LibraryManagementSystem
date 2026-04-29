//
// Coded by noah s + Kami I. on 3/24/26 and 4/20/26.
//

#ifndef FINALPROJECT_MAGAZINE_H
#define FINALPROJECT_MAGAZINE_H

#include <string>
#include "FileHandler.h"

using namespace std;

class Magazine {
    private:
        FileHandler fileReference;

        string title = "";
        string author = "";
        string classification = "";
        bool isBorrowed;
        int yearPublished = 0;

        int dueDay = 0;
        int dueMonth = 0;
        int dueYear = 0;

    public:
        Magazine();

        void displayMagazines();

        string addMagazine(string title, string author, string classification);
        string removeMagazine(string title);
};


#endif //FINALPROJECT_MAGAZINE_H
