//
// Coded by Kami I. on 4/20/26.
//

/**
 *Magazine.cpp:
 *
 *Description: Reads information on the requested magazine
 *
 */

#include "Magazine.h"

Magazine::Magazine()
{
    title = "";
    author = "";
    isBorrowed = false;
    yearPublished = 0;

    dueDay = 0;
    dueMonth = 0;
    dueYear = 0;
}
