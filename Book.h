//
// Coded by noah s on 3/24/26.
//

#ifndef FINALPROJECT_BOOK_H
#define FINALPROJECT_BOOK_H

#include <string>

using namespace std;

class Book {
    private:
        string title;
        string author;
        string classification; // organizes in alphebetical order and catagories
        bool isBorrowed;
        int yearPublished;

        int dueDay;
        int dueMonth;
        int dueYear;

    public:
        void displayBook(Book b);
        void borrowBook(Book &b);
        void returnBook(Book &b, int currentDay, int currentMonth, int currentYear);
        void setDueDate(Book &b, int day, int month, int year, string accountType);
        void extendDueDate(Book &b);
};


#endif //FINALPROJECT_BOOK_H
