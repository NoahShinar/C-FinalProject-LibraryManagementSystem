//
// Coded by Kami I. on 4/15/26.
//

#include "AccountTypeEnum.h"
#include <string>

using namespace std;

string enumToString(AccountTypeEnum type) {
    switch (type) {
        case AccountTypeEnum::STUDENT:
            return "STUDENT";
        case AccountTypeEnum::FACULTY:
            return "FACILITY";
        case AccountTypeEnum::STAFF:
            return "STAFF";
        default:
            return "UNKNOWN";
    }
}