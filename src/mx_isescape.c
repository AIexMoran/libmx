#include "libmx.h"

bool mx_isescape(char c) {
    if (c == '\a' || c == '\b' || c == '\f' || c == '\n'
        || c == '\r' || c == '\t' || c == '\v') {
        return true;
    }
    return false;
}
