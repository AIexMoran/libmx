#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int len = 0;
    int base = 1;

    if (!hex)
        return 0;
    len = mx_strlen(hex);
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9')
            result += (hex[i] - '0') * base;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            result += (hex[i] - '0') * base;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            result += (hex[i] - '0') * base;
        base *= 16;
    }
    return result;
}
