#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double temp = n;

    if (pow <= 0) {
        return 1;
    }
    for(;pow - 1 > 0; --pow) {
        n *= temp;
    }
    return n;
}
