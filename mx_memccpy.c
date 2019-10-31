#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *dst_c = dst;
    unsigned const char *src_c = src;
    size_t index = 0;

    while (index < n) {
        dst_c[index] = src_c[index];
        if (dst_c[index] == (unsigned char) c) {
            return (void *) ((unsigned char)dst + index + 1);
        }
        index++;
    }
    return NULL;
}
