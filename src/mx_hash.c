#include "libmx.h"

unsigned int mx_hash(void *data) {
    const unsigned char *bytes = data;
    unsigned int hash = 7;

    for (int i = 0; i < mx_strlen(data); i++) {
        hash = (hash << 5) + hash + bytes[i];
    }
    return hash;
}
