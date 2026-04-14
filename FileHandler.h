//
// Coded by noah s on 4/1/26.
//

#ifndef FINALPROJECT_FILEHANDLER_H
#define FINALPROJECT_FILEHANDLER_H

#import <string>

using namespace std;

class FileHandler {
    private:
        const string ACCOUNTS_FILE = "/home/noahs/CLionProjects/FinalProject/RegisteredAccounts.txt";
        const string LIBRARY_FILE = "/home/noahs/CLionProjects/FinalProject/Library.txt";

        string RegisterAccount();
        string libraryFile();
};


#endif //FINALPROJECT_FILEHANDLER_H
