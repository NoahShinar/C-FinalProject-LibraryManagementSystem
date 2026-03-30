//
// Coded by Kami I. on 3/30/36.
//

#include "Accounts.h"
#include <iostream>

using namespace std;

//
string Accounts::borrowedBooks()
{
    return "No books stored";
}

string Accounts::borrowedMagazines()
{
    return "No magazines stored";
}

int Accounts::maxBorrowTime()
{
    if (type == "Student")
    {
        return 30; //days loaned
    }
    else if (type == "Faculty" || type == "Staff")
    {
        return 60; //days loaned
    }
    else
    {
        return 30; //default
    }
}

