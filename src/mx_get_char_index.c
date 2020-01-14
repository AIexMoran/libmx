#include "libmx.h"

int mx_strlen(const char *str);

int mx_get_char_index(const char *str, char c) {
    if (!str) {
        return -2;
    }
    for (int i = 0; i < mx_strlen(str); i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}
