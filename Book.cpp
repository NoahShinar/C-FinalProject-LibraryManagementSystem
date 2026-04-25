//
// Coded by Kami I. on 3/30/26.
//

/**
* Book.cpp:
* Description: Class that implements book class functions
*
* Handles:
* -display borrowed books
* -borrows and returns books
* -sets and extends due dates
* -add books to Books.txt
*
* @author Kami Iwanski
* @author Noah Shinar
*/

#include "Book.h"
#include "FileHandler.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Description: Function to display the book information
 *
 * @param b Book being displayed
 *
 * @return book information
 */
void Book::displayBook (Book b) {
     cout << "Title: " << b.title << endl;
     cout << "Author: " << b.author << endl;
     cout << "Classification: " << b.classification << endl;
     cout << "Year: " << b.yearPublished << endl;
     cout << "Borrowed Status: " << (b.isBorrowed ? "Borrowed" : "Still available") << endl;
}

/**
 * Description: Function that loans (borrows) a book for the user
 *
 * @param b Book being loaned
 *
 * @return Status of borrowed book (success or error)
 */
void Book::borrowBook (Book &b) {
    if (!b.isBorrowed) {
     b.isBorrowed = true;
        cout << "Book successfully borrowed\n";
    }
    else {
        cout << "Book already borrowed\n";
    }
}

/**
 * Description: Function that returns a book from being loaned
 *
 * @param b Book being returned from loan
 *
 * @param currentDay Displays current day returned
 *
 * @param currentMonth Displays current month returned
 *
 * @param currentYear Displays current year returned
 *
 * @return Returns late message + fine or success message for no fine
 */
void Book::returnBook (Book &b, int currentDay, int currentMonth, int currentYear) {
    b.isBorrowed = false;

    int lateDays = currentDay - b.dueDay;

    if (lateDays > 0) {
     double fine = lateDays * 1.75;
        cout << "Late return. Calculated fine: $" << fine << endl;
    }
    else {
     cout << "Returned on time!\n";
    }
}

/**
 * Description: Function that calculates due date
 *
 * @param b Book being loaned
 *
 * @param day Day book is due to be returned
 *
 * @param month Month book is due to be returned
 *
 * @param year Year book is due to be returned
 *
 * @param accountType Type of account requesting book loan
 *
 * @return The due date set for the book being loaned
 */
void Book::setDueDate (Book &b, int day, int month, int year, string accountType) {
    int borrowDays;

    if (accountType == "Student") {
        borrowDays = 30;
    }
    else if (accountType == "Faculty" || accountType == "Staff") {
      borrowDays = 60;
    }
    else {
      borrowDays = 30; //default
    }
    b.dueDay = day + borrowDays;
    b.dueMonth = month;
    b.dueYear = year;
}

/**
 * Description: Function that extends the due date on a loaned book
 *
 * @param b Book with the due date that is being modified
 *
 * @return Successful extension message
 */
void Book::extendDueDate (Book &b) {
    b.dueDay += 10;
    cout << "Due date extended by 10 days. Enjoy!\n";
}

/**
 * Function that adds a book to the library
 *
 * @param title title of book
 * @param author author of book
 * @param classification organizes in alphebetical order and catagories
 *
 * @return string into book.txt of the added book
 */
string Book::addBook(string title, string author, string classification) {

    fstream file(fileReference.BOOKS_FILE, ios::out | ios::app);

    if (!file) {
        cerr << "Unable to open file: " << fileReference.BOOKS_FILE << endl;
        return "Error: Could not open file";
    }

    file << classification << " - " << title << " - " << author << endl;
    file.close();

    return "Book added successfully";
}

/**
 * Function that removes a book from the library
 *
 * @param title title of book
 *
 * @return string into Book.txt of the removed book
 */
string Book::removeBook(string title) {

    ifstream file(fileReference.BOOKS_FILE);
    ofstream tempFile(fileReference.TEMP_FILE); // Creates temp file

    if (!file || !tempFile) {
        cerr << "Unable to open file: " << fileReference.BOOKS_FILE << endl;
        return "Error: Could not open file";
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(" - " + title + " - ") != string::npos) {
            found = true;
        }
        else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    // Swap the files
    remove(fileReference.BOOKS_FILE.c_str()); // Delete old file
    rename(fileReference.TEMP_FILE.c_str(), fileReference.BOOKS_FILE.c_str()); // Rename temp file to accounts file name

    if (found) {
        return "Book removed successfully";
    }
    else {
        return "Book not found";
    }
}
