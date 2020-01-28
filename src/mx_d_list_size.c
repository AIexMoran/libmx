#include "libmx.h"

int mx_d_list_size(t_d_list *list) {
    int count = 1;
    t_d_list *tmp = list;

    if (!list)
        return 0;
    while (tmp->next) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
