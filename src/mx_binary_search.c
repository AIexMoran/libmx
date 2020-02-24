#include "libmx.h"

static bool check(int *low, int *high, int med, int cmp) {
    if (cmp == 0)
        return true;
    if (cmp < 0)
        *low = med + 1;
    else
        *high = med - 1;
    return false;
}

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0;
    int high = size - 1;
    int med = 0;
    int cmp = 0;

    *count = 0;
    if (!s || !arr)
        return -1;
    while (low <= high) {
        med = low + (high - low) / 2;
        cmp = mx_strcmp(arr[med], s);
        (*count)++;
        if (check(&low, &high, med, cmp)) {
            return med;
        }
    }
    *count = 0;
    return -1;
}
