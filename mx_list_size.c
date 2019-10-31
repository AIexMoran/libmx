#include "libmx.h"

int mx_list_size(t_list *list) {
    int result = 0;
    t_list *current = list;

    while (current) {
        result++;
        current = current->next;
    }
    return result;
}
