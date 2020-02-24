#include "libmx.h"

static int pos(int num) {
    if (num < 0)
        return -num;
    return num;
}

char *mx_itoa(int number) {
    int len = mx_numlen(number);
    char *result = mx_strnew(len);

    if (number < 0)
        result[0] = '-';
    if (number == 0)
        result[0] = '0';
    for (int i = len - 1; number; i--) {
        result[i] = pos(number % 10) + '0';
        number /= 10;
    }
    return result;
}
