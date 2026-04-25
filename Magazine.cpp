//
// Coded by Kami I. on 4/20/26.
//

/**
* Magazine.cpp:
* Description: Class that implements magazine class functions
*
* Handles:
* -display borrowed magazines
* -borrows and returns magazines
* -sets and extends due magazines
* -add magazines to Magazine.txt
*
* @author Kami Iwanski
* @author Noah Shinar
*/


#include "Magazine.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * Description: Magazine constructor
 *
 */
Magazine::Magazine() {
    title = "";
    author = "";
    classification = "";
    isBorrowed = false;
    yearPublished = 0;

    dueDay = 0;
    dueMonth = 0;
    dueYear = 0;
}

/**
 * Description: adds magazines to Magazine.txt
 *
 * @param title title of magazine
 * @param author author of magazine
 * @param classification classification of magazine
 * @return
 */
string Magazine::addMagazine(string title, string author, string classification) {

    fstream file(fileReference.MAGAZINES_FILE, ios::out | ios::app);

    if (!file) {
        cerr << "Unable to open file: " << fileReference.MAGAZINES_FILE << endl;
        return "Error: Could not open file";
    }

    file << classification << " - " << title << " - " << author << endl;
    file.close();

    return "Magazine added successfully";
}

/**
 * Function that removes a magazine from the library
 *
 * @param title title of magazine
 *
 * @return string into Magazine.txt of the removed magazine
 */
string Magazine::removeMagazine(string title) {

    ifstream file(fileReference.MAGAZINES_FILE);
    ofstream tempFile(fileReference.TEMP_FILE); // Creates temp file

    if (!file || !tempFile) {
        cerr << "Unable to open file: " << fileReference.MAGAZINES_FILE << endl;
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
    remove(fileReference.MAGAZINES_FILE.c_str()); // Delete old file
    rename(fileReference.TEMP_FILE.c_str(), fileReference.MAGAZINES_FILE.c_str()); // Rename temp file to accounts file name

    if (found) {
        return "Magazine removed successfully";
    }
    else {
        return "Magazine not found";
    }
}

