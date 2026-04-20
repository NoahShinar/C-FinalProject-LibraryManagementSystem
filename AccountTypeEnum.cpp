//
// Coded by Kami I. on 4/15/26.
//

#include "AccountTypeEnum.h"
#include <string>

using namespace std;

string AccountTypeToString(AccountTypeEnum type)
{
    if (type == AccountTypeEnum::STUDENT)
        return "STUDENT";
    else if (type == AccountTypeEnum::FACULTY)
        return "FACULTY";
    else if (type == AccountTypeEnum::STAFF)
        return "STAFF";
}