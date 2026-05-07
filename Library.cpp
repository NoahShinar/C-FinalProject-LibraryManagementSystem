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
 * @author Noah Shinar
 * @author Kami I
 *
 * @return everything in Book.txt
 */
void Library::displayBooks() {

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
 * @author Noah Shinar
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

/**
 * Description: Function that returns a book or magazine from being loaned
 *
 * @author Noah Shinar
 *
 * @param account account to remove borrowed book from
 * @param title Book or magazine being returned
 *
 * @return Returns late message + fine or success message for no fine
 */
string Library::returnBookOrMagazine(string title, int account) {
    string sourceFile = "";
    string fullInfo = "";
    bool found = false;

    // 1. Determine if it's in Books or Magazines
    string files[] = {fileReference.BOOKS_FILE, fileReference.MAGAZINES_FILE};
    for (const string& currentFile : files) {
        ifstream file(currentFile);
        ofstream tempFile(fileReference.TEMP_FILE);
        string line;

        while (getline(file, line)) {
            if (!found && line.find(title) != string::npos && line.find(" - UNAVAILABLE") != string::npos) {
                fullInfo = line.substr(0, line.find(" - UNAVAILABLE"));
                size_t pos = line.find(" - UNAVAILABLE");
                line.replace(pos, 14, " - AVAILABLE");
                found = true;
                sourceFile = currentFile;
            }
            tempFile << line << endl;
        }
        file.close();
        tempFile.close();

        if (found) {
            remove(currentFile.c_str());
            rename(fileReference.TEMP_FILE.c_str(), currentFile.c_str());
            break;
        }
        else {
            remove(fileReference.TEMP_FILE.c_str());
        }
    }

    if (!found) return "Error: Item not found or already returned.";

    // 2. Update Account File
    ifstream accFile(fileReference.ACCOUNTS_FILE);
    ofstream accTemp(fileReference.TEMP_FILE);
    if (!accFile || !accTemp) return "Error: Could not open accounts file";

    string line;
    string target = " | Borrowed: " + fullInfo;
    int currentLine = 1;

    while (getline(accFile, line)) {
        if (currentLine == account) {
            size_t pos = line.find(target);
            if (pos != string::npos) line.erase(pos, target.length());
        }
        accTemp << line << endl;
        currentLine++;
    }

    accFile.close();
    accTemp.close();
    remove(fileReference.ACCOUNTS_FILE.c_str());
    rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());

    return "Item returned successfully.";
}

/**
 * Function that extends borrow time
 *
 * @author Kami I
 *
 * @param title book title
 * @param account account name
 *
 * @return extention time to item
 */
string Library::extendItem(string title, int account)
{
    ifstream file(fileReference.ACCOUNTS_FILE);
    ofstream temp(fileReference.TEMP_FILE);

    if (!file || !temp) {
        return "Error opening file.";
    }

        string line;
        bool found = false;

        while (getline(file, line))
        {
            if (!found && line.find(title) != string::npos && line.find("Unavailable") != string::npos) {
                line += " --> extended +10 days";
                found = true;
            }
            temp << line << endl;
        }
        file.close();
        temp.close();

        if (!found) {
            remove(fileReference.TEMP_FILE.c_str());
            return "Item not found.";
        }

        remove(fileReference.ACCOUNTS_FILE.c_str());
        rename(fileReference.TEMP_FILE.c_str(), fileReference.ACCOUNTS_FILE.c_str());

        return "Extension applied to item.";
    }

/**
 * Function that prints menu items
 *
 * @author Noah Shinar
 *
 * @return menu
 */
void Library::printMenu() {
    cout << endl;
    cout << "1. add new account" << endl; // Done
    cout << "2. remove account" << endl; // Done
    cout << "3. add book or magazine to the library" << endl; // Done
    cout << "4. remove book or magazine from the library" << endl; // Done
    cout << "5. borrow book or magazine" << endl; // Done
    cout << "6. return book or magazine" << endl; // Done
    cout << "7. view account" << endl; // Done
    cout << "8. request extension" << endl; // Done (somewhat)
    cout << "9. exit program" << endl; // Done
}