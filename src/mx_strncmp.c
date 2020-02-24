#include "libmx.h"

static int charcmp(char c1, char c2) {
    return c1 - c2;
}

int mx_strncmp(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (charcmp(s1[i], s2[i])) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
