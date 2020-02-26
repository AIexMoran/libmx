#include "libmx.h"

static int length_str(unsigned long nbr) {
    int length = nbr == 0 ? 1 : 0;

    while (nbr) {
        nbr /= 16;
        length++;
    }
    return length;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    int len = length_str(nbr);
    char *result = mx_strnew(len);
    int temp = 0;

    if (!nbr)
        result[0] = '0';    
    while (nbr) {
        temp = nbr % 16;
        if (temp < 10)
            result[len - 1] = temp + '0';
        else
            result[len - 1] = temp + 'a' - 10;
        len--;
        nbr /= 16;
    }
    return result;
}
