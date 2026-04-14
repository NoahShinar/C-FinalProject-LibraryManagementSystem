//
// Created by noahs on 4/1/26.
//

#include "FileHandler.h"
#include <fstream>

using namespace std;

string FileHandler::RegisterAccount() {
    ifstream file(ACCOUNTS_FILE);

    if (!file) {
        cerr << "unable to open file: " << ACCOUNTS_FILE << endl;
        exit(EXIT_FAILURE);
    }

    while (!file.eof()) {
        getline(file, name, ',');
    }

    file.close();
}
string FileHandler::libraryFile() {

}