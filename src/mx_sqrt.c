#include "libmx.h"

int mx_sqrt(int n) {
    int num = 1;

    if (n < 0) {
        return 0;
    }
    if (n == 0 || n == 1) {
        return n;
    }
    while (num < 46341 && num < n / 2) {
        num++;
        if (num * num == n) {
            return num;
        } 
    }
    return 0;
}
