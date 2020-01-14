#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *ds = (unsigned char *)dst;
    unsigned char *sr = (unsigned char *)src;
    size_t i = 0;
    
    for(; i < n && sr[i] != c; i++)
        ds[i] = sr[i];
    if (sr[i] == c) {
        ds[i] = sr[i];
        return &ds[i + 1];
    }
    return NULL;
}
