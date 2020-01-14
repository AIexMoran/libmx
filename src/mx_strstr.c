#include "libmx.h"

int mx_strlen(const char *str);
int mx_strncmp(const char *s1, const char *s2, size_t n);

char *mx_strstr(const char *haystack, const char *needle) {
    const char *save_haystack = haystack;
    int needle_length = mx_strlen(needle);
    
    if (!needle_length) {
        return (char *) haystack;
    }
    for (int i = 0; i <= mx_strlen(save_haystack) - needle_length; i++) {
        if (!mx_strncmp(haystack, needle, needle_length)) {
            return (char *) haystack;
        }
        haystack++;
    }

    return NULL;
}
