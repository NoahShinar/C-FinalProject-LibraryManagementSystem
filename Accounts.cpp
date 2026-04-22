//
// Coded by Kami I. on 3/30/36.
//

#include "Accounts.h"

using namespace std;

string Accounts::borrowedBooks() {
    return "No books stored";
}

string Accounts::borrowedMagazines() {
    return "No magazines stored";
}

int Accounts::maxBorrowTime(int inputType) {

    type = static_cast<AccountTypeEnum>(inputType);

    if (type == AccountTypeEnum::STUDENT) {
        return 30; //days loaned
    }
    else if (type == AccountTypeEnum::FACULTY || type == AccountTypeEnum::STAFF) {
        return 60; //days loaned
    }
    else {
        return 30; //default
    }
}
string Accounts::ReviewAccount() {

}

