#include "libmx.h"

void mx_printint(int n) {
    char *str = mx_itoa(n);

    mx_printstr(str);
    mx_strdel(&str);
}
