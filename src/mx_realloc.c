#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);

void *mx_realloc(void *ptr, size_t size) {
    void *result = NULL;

    if (!ptr && size) {
        return malloc(size);
    }
    if (!size && ptr) {
        free(ptr);
        result = malloc(malloc_size(NULL));
        mx_memcpy(result, "", 16);
        return result;
    }
    result = malloc(size);
    mx_memcpy(result, ptr, malloc_size(ptr));
    free(ptr);
    return result;
}
