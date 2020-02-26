#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len) {
    const unsigned char *big_c = big;
    const unsigned char *little_c = little;

    if (big_len < little_len || !big_len || !little_len) {
        return NULL;
    }
    if (little_len == 1) {
        return mx_memchr(big, (int)*little_c, big_len);
    }
    for (size_t i = 0; i < big_len - little_len + 1; i++) {
        if (!mx_memcmp(big_c, little_c, little_len)) {
            return (void*)big_c;
        }
        big_c++;
    }
    return NULL;
}
