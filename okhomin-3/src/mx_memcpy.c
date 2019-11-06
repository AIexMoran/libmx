#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    char *dst_c = dst;
    const char *src_c = src;

    while (n--) {
        *dst_c = *src_c;
        dst_c++;
        src_c++;
    }
    return dst;
}
