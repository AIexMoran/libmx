#include "libmx.h"

char *mx_pr_num_to_hex(unsigned long num) {
    char *result = mx_strdup("0x00000000");
    int temp = 0;

    for (int i = 0; num; i++) {
        temp = num % 16;
        if (temp < 10)
            result[9 - i] = '0' + temp;
        else
            result[9 - i] = 'a' + temp - 10;
        num /= 16;
    }
    return result;
}
