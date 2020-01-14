#include "libmx.h"

static int swap(char **str1, char **str2)
{
    char *tmp = *str1;
    
    *str1 = *str2;
    *str2 = tmp;
    return 1;
}

static int partition(char **arr, int l, int r, int *swap_count) {
    int pivot = mx_strlen(arr[l + (r - l) / 2]);
    int i = l - 1;
    int j = r + 1;

    while (69) {
        while (mx_strlen(arr[++i]) < pivot);
        while (mx_strlen(arr[--j]) > pivot);
        if (i >= j)
            return j;
        swap(&(arr[i]), &(arr[j])) && ++(*swap_count);
    }
}

int mx_quicksort(char **arr, int left, int right)
{
    int swap_count = 0;
    if (left < right) {
        int p = partition(arr, left, right, &swap_count);        
        return (swap_count + mx_quicksort(arr, left, p) + mx_quicksort(arr, p + 1, right));
    }
    return 0;
}
