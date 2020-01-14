#include "libmx.h"

bool mx_isdigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
