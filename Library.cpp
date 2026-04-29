//
// Coded by Kami I. on 4/20/26. Finished by Noah S on 4/21/26.
//

/**
 *Library.cpp:
 *
 *Description: Class to handle the library file as a whole
 *
 *@Authors Kami Iwanski and Noah Shinar
 */

#include "Library.h"
#include "FileHandler.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Description: Function to display books
 *
 * @return everything in Book.txt
 */
void Library::displayBooks() {
    // cout << "Title: " << b.title << endl;
    // cout << "Author: " << b.author << endl;
    // cout << "Classification: " << b.classification << endl;
    // cout << "Year: " << b.yearPublished << endl;
    // cout << "Borrowed Status: " << (b.isBorrowed ? "Borrowed" : "Still available") << endl;

    int lineCount = 1;
    string line;
    ifstream file(fileReference.BOOKS_FILE);

    if (!file) {
        cerr << "Error opening input file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Books:" << endl;

    while (getline(file, line)) {
        if (!line.empty()) {
            cout << lineCount << ". " << line << endl;
            lineCount++;
        }
    }

    file.close();
}

/**
 * Description: Function to display the magazines
 *
 * @return everything in Magaziens.txt
 */
void Library::displayMagazines() {

    int lineCount = 1;
    string line;
    ifstream file(fileReference.MAGAZINES_FILE);

    if (!file) {
        cerr << "Error opening input file" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Magazines:" << endl;

    while (getline(file, line)) {
        if (!line.empty()) {
            cout << lineCount << ". " << line << endl;
            lineCount++;
        }
    }

    file.close();
}