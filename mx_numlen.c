#include "libmx.h"

int mx_numlen(int num) {
    int len = num < 0 ? 1 : 0;

    while (num > 0 || -num > 0 || num == -2147483648) {
        num /= 10;
        len++;
    }
    return len == 0 ? 1 : len;
}
