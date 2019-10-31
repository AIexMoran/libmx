#include "libmx.h"

int mx_strlen(const char *s1);
static void swap(char **arr, int first, int second);
static int partition(char **arr, int low, int high, int *count);

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) {
        return -1;
    }
    int count = 0;
    int index = partition(arr, left, right, &count);

    if (left < index - 1) {
        count += mx_quicksort(arr, left, index - 1);
    }
    if (index < right) {
        count += mx_quicksort(arr, index, right);
    }
    return count;
}

static int partition(char **arr, int left, int right, int *count) {
    int i = left;
    int j = right;
    char *pivot = arr[left + (right - left) / 2];

    while (i <= j) {
        while (mx_strlen(arr[i]) < mx_strlen(pivot)) {
            i++;
        }
        while (mx_strlen(arr[j]) > mx_strlen(pivot)) {
            j--;
        }
        if (i <= j) {
            if (i != j && mx_strlen(arr[j]) != mx_strlen(arr[i])) {
                swap(arr, i, j);
                (*count)++;
            }
            i++;
            j--;
        }
    }
    return i;
}

static void swap(char **arr, int first, int second) {
    char *tmp = arr[first];

    arr[first] = arr[second];
    arr[second] = tmp;
}
