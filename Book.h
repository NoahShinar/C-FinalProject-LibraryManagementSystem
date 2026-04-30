//
// Coded by noah s on 3/24/26.
//

/**
 * Book.h:
 * Header file for Book.cpp
 *
 * @author Noah S
 * @author Kami I
*/

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>
#include "FileHandler.h"

using namespace std;

class Book {
    private:
        FileHandler fileReference;

        string title;
        string author;
        string classification; // organizes in alphebetical order and catagories
        bool isBorrowed;
        int yearPublished;

        int dueDay;
        int dueMonth;
        int dueYear;

    public:
        void displayBooks();
        string borrowBook(int selection, int account);
        string returnBook(int selection, int account);
        void setDueDate(Book &b, int day, int month, int year, string accountType);
        void extendDueDate(Book &b);
        string addBook(string title, string author, string classification);
        string removeBook(string title);
};


#endif //FINALPROJECT_BOOK_H
