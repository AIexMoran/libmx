#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>

void mx_pop_front(t_list **head) {
    t_list *next_node = NULL;

    if (!(*head)) {
        return;
    }
    next_node = (*head)->next;
    (*head)->data = NULL;
    free(*head);
    *head = next_node;
}
