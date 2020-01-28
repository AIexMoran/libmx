#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *tmp = *head;

    if (!tmp)
        return;
    while (tmp->next && tmp->next->next) {
        tmp = tmp->next;
    }
    free(tmp->next->data);
    free(tmp->next);
    tmp->next = NULL;
}
