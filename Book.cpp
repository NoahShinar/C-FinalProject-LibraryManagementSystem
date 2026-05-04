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
 * @param account account to add borrowed book to
 * @param selection Book being loaned
 *
 * @return Status of borrowed book in Books.txt and RegisteredAccounts.txt
 */
string Book::borrowBook(int selection, int account) {
    ifstream file(fileReference.BOOKS_FILE);
    ofstream tempFile(fileReference.TEMP_FILE);

    if (!file || !tempFile) {
        cerr << "Unable to open file" << endl;
        return "Error: Could not open file";
    }

    string line;
    string bookInfo = ""; // Variable to store the specific book details
    int currentLine = 1;
    bool bookFound = false;

    // 1. Update Books File and Extract Info
    while (getline(file, line)) {
        if (currentLine == selection) {
            size_t pos = line.find(" - AVAILABLE");
            if (pos != string::npos) {
                // Store the book info (everything before " - AVAILABLE")
                bookInfo = line.substr(0, pos);

                line.replace(pos, 12, " - UNAVAILABLE");
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

    // 2. Update Account File (Append book info string)
    ifstream accFile(fileReference.ACCOUNTS_FILE);
    ofstream accTemp(fileReference.TEMP_FILE);

    if (!accFile || !accTemp) {
        return "Error: Could not open accounts file";
    }

    currentLine = 1;
    while (getline(accFile, line)) {
        if (currentLine == account) {
            // Append the actual book string instead of the selection number
            line += " | Borrowed: " + bookInfo;
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

    file << classification << " - " << title << " - " << author << " - " << "AVAILABLE" << endl;
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
