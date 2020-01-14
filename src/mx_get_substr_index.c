#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    char *result = NULL;
    
    if (!str || !sub) {
        return -2;
    }
    result = mx_strstr(str, sub);
    if (result) {
        return result - str;
    }
    return -1;
}
