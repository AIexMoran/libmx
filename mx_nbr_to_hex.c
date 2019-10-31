#include "libmx.h"

char *mx_strnew(const int size);

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long tmp_nbr = nbr;
    int length = 0;
    char *result = NULL;
    int i = 0;

    if (nbr == 0) {
        return "0";
    }
    while (tmp_nbr > 0) {
        tmp_nbr /= 16;
        length++;
    }
    result = mx_strnew(length);
    i = length - 1;
    while (nbr > 0) {
        int tmp = nbr % 16;

        if (tmp < 10) {
            result[i] = tmp + '0';
        }
        else {
            result[i] = tmp + 87;
        }
        nbr /= 16;
        i--;
    }
    return result;
}
