#include "libmx.h"

void mx_d_del_list(t_d_list **list) {
    t_d_list *tmp;

    while (*list) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp->data);
        free(tmp);
    }
}
