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
 * Description: Function that loans a book to the user
 *
 * @author Noah Shinar
 *
 * @param account account to add borrowed book to
 * @param selection Book being loaned
 *
 * @return Status of borrowed book in Books.txt and RegisteredAccounts.txt
 */
string Book::borrowBook(int selection, int account) {

    ifstream accFile(fileReference.ACCOUNTS_FILE);
    string line;
    string accountLine = "";

    int currentLine = 1;
    bool accountFound = false;

    while (getline(accFile, line)) {

        if (currentLine == account) {

            accountLine = line;
            accountFound = true;
            break;

        }
        currentLine++;
    }

    accFile.close();

    if (!accountFound) {
        return "Error: Account not found";
    }

    int borrowedCount = 0;
    size_t pos = accountLine.find("| Borrowed:");

    while (pos != string::npos) {
        borrowedCount++;
        pos = accountLine.find("| Borrowed:", pos + 1);
    }


    int limit;
    if (accountLine.find("STUDENT") != string::npos) {
        limit = 5;
    }

    else {
        limit = 10;
    }


    if (borrowedCount >= limit) {
        cout << "Error: Maximum borrow limit reached" << endl;
        return "Error: Maximum borrow limit reached";
    }


    ifstream file(fileReference.BOOKS_FILE);
    ofstream tempFile(fileReference.TEMP_FILE);
    string bookInfo = "";
    currentLine = 1;
    bool bookFound = false;

    while (getline(file, line)) {

        if (currentLine == selection) {
            size_t posAvailable = line.find(" - AVAILABLE");
                if (posAvailable != string::npos) {
                    bookInfo = line.substr(0, posAvailable);
                    line.replace(posAvailable, 12, " - UNAVAILABLE");
                    bookFound = true;
                }
            }

        tempFile << line << endl;
        currentLine++;
    }

    file.close();
    tempFile.close();


    if (!bookFound) {
        remove(fileReference.TEMP_FILE.c_str());
        return "Error: Book selection invalid or already borrowed";
    }


    remove(fileReference.BOOKS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.BOOKS_FILE.c_str());

    accFile.open(fileReference.ACCOUNTS_FILE);
    ofstream accTemp(fileReference.TEMP_FILE);

    int borrowDays = (accountLine.find("STUDENT") != string::npos) ? 30 : 60;

    currentLine = 1;


    while (getline(accFile, line)) {

        if (currentLine == account) {
            line += " | Borrowed: " + bookInfo + " | Duration: " + to_string(borrowDays) + " days";
        }

        accTemp << line << endl;

        currentLine++;
    }

    accFile.close();
    accTemp.close();

    remove(fileReference.ACCOUNTS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());

    return "Book borrowed successfully.";
}

/**
 * Description: Function that calculates due date
 *
 * @author Kami I
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
 * @author Kami I
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
 * @author Noah Shinar
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

    file << classification << " - " << title << " - " << author << " - " << "AVAILABLE" << endl;
    file.close();

    return "Book added successfully";
}

/**
 * Function that removes a book from the library
 *
 * @author Noah Shinar
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
