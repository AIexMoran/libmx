#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    char **result = NULL;
    int size = 0;
    int index = 0;
    int counter = 0;

    if (!s)
        return NULL;
    size = mx_count_words(s, c);
    result = malloc(sizeof(char*) * (size + 1));
    while (*s) {
        index = mx_get_char_index(s, c);
        index = index == -1 ? mx_strlen(s) : index;
        if (index) {
            result[counter] = mx_strndup(s, index);
            s += mx_strlen(result[counter++]) - 1;
        }
        s++;
    }
    result[size] = NULL;
    return result;
}
