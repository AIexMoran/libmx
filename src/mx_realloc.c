#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    size++;    
    return ptr;
}
