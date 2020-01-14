#include "libmx.h"

void mx_printchar(char c);

void mx_printint(int n) {
    if (n == -2147483648) {
        mx_printchar('-');
        mx_printchar('2');
        n += 2000000000;
        n *= -1;
    }
    else if (n < 0) {
        mx_printchar('-');
        n *= -1;
    }
    if (n < 10) {
        mx_printchar(n + '0');
        return;
    }
    mx_printint(n / 10);
    mx_printchar(n % 10 + '0');
}
