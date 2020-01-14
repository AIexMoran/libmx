#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle);

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2;
    }
    char *result = mx_strstr(str, sub);
    
    if (result) {
        return result - str;
    }
    return -1;
}
