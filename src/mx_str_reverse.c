#include "libmx.h"

void mx_str_reverse(char *s) {
    int length = 0;

    if (!s)
        return;
    length = mx_strlen(s);
    for (int i = 0; i < length / 2; i++) {
        mx_swap_char(&s[i], &s[length - i - 1]);
    }
}
