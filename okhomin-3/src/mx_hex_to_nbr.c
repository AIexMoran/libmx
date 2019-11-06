#include "libmx.h"

int mx_strlen(const char *s);

unsigned long mx_hex_to_nbr(const char *hex) {
    if (!hex) {
        return 0;
    }
    unsigned long result = 0;
    int len = mx_strlen(hex);
    int val = 0;
    unsigned long tmp_val = 0;

    for (int i = 0; i < len; i++) {
        if (*hex >= 'A' && *hex <= 'F') {
            val = *hex - 'A' + 10;
        }
        else if (*hex >= 'a' && *hex <= 'f') {
            val = *hex - 'a' + 10;
        }
        else if (*hex >= '0' && *hex <= '9') {
            val = *hex - '0';
        }
        tmp_val = 1;
        for (int j = 0; j < len - i - 1; j++) {
            tmp_val *= 16;
        }
        result += val * tmp_val;
        hex++;
    }
    return result;
}
