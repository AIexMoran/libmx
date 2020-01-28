#include "libmx.h"

void mx_d_pop_back(t_d_list **head) {
    t_d_list *tmp = *head;

    if (!tmp)
        return;
    while (tmp->next && tmp->next->next) {
        tmp = tmp->next;
    }
    free(tmp->next->data);
    free(tmp->next);
    tmp->next = NULL;
}
