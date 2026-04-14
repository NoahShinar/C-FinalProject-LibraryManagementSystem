//
// Coded by Kami I. on 3/30/36.
//

#include "Accounts.h"
#include <iostream>

using namespace std;

string Accounts::borrowedBooks() {
    return "No books stored";
}

string Accounts::borrowedMagazines() {
    return "No magazines stored";
}

int Accounts::maxBorrowTime(int inputType) {

    type = static_cast<TYPE>(inputType);

    if (type == STUDENT) {
        return 30; //days loaned
    }
    else if (type == FACILITY || type == STAFF) {
        return 60; //days loaned
    }
    else {
        return 30; //default
    }
}

