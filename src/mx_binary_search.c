#include "libmx.h"

int mx_strcmp(const char *s1, const char *s2);

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int low = 0;
    int high = size - 1;
    int med = 0;
    *count = 0;

    if (!s || !arr) {
        return -1;
    }
    while (low <= high) {
        med = low + (high - low) / 2;

        (*count)++;
        if (mx_strcmp(arr[med], s) == 0) {
            return med;
        }
        if (mx_strcmp(arr[med], s) < 0) {
            low = med + 1;
        }
        else if (mx_strcmp(arr[med], s) > 0) {
            high = med - 1;
        }
    }
    *count = 0;
    return -1;
}
