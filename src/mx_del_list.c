#include "libmx.h"

void mx_del_list(t_list **head) {
    t_list *tmp;

    while (*head) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp->data);
        free(tmp);
    }
}
