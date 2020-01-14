#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *tmp = *head;

    if (!*head)
        return;
    while (tmp->next) {
        if (!tmp->next->next) {
            break;
        }
        tmp = tmp->next;
    }
    free(tmp->next->data);
    free(tmp->next);
    tmp->next = NULL;
}
