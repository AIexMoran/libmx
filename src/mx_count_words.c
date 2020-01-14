#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int word = 0;
    int words = 0;

    if (!str) {
        return -1;
    }
    while (*str) {
        if (*str == c) {
            word = 0;
        }
        else if (!word) {
            word = 1;
            words++;
        }
        str++;
    }
    return words;
}
