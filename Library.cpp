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
#include <iostream>
#include <fstream>

using namespace std;

/**
 *Description: List of all books the library possesses
 *
 * @return full list of books in the library
 */
string Library::listBooks() {

    ifstream file(fileReference.BOOKS_FILE);

    if (!file) {
        return "Error: Could not open file";
    }

    while (getline(file, input)) {
        lineCount++;
        cout << "Book: " << input << endl;
    }

    file.close();
}

/**
 *Description: List all magazines the library possesses
 *
 * @return full list of magazines in the library
 */
string Library::listMagazines() {

    ifstream file(fileReference.MAGAZINES_FILE);

    if (!file) {
        return "Error: Could not open file";
    }

    while (getline(file, input)) {
        lineCount++;
        cout << "Magazine: " << input << endl;
    }

    file.close();
}