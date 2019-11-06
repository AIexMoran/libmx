#include "libmx.h"

char *mx_strnew(const int size);
int mx_numlen(int num);

char *mx_itoa(int number) {
    int len = mx_numlen(number);
    char *result = mx_strnew(len);
    int min = 0;

    if (number == -2147483648) {
        result[0] = '-';
        result[1] = '2';
        min += 2;
        number += 2000000000;
        number *= -1;
    }
    else if (number < 0) {
        result[0] = '-';
        min++;
        number *= -1;
    }
    for (int i = len - 1; i >= min; i--) {
        result[i] = (number % 10) + '0';
        number /= 10;
    }
    return result;
}
