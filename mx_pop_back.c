#include "libmx.h"
#include <stdlib.h>
#include <stdio.h>

void mx_pop_back(t_list **head) {
    if ((*head)->next == NULL) {
        (*head)->data = NULL;
        free(*head);
        return;
    }
    t_list *current = *head;

    while (current->next->next != NULL) {
        current = current->next;
    }
    current->next->data = NULL;
    free(current->next);
    current->next = NULL;
}
