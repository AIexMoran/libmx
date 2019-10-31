#include "libmx.h"

int mx_list_size(t_list *list);
static void swap(t_list *n1, t_list *n2);

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    int size = mx_list_size(lst);
    t_list *start = lst;
    for (int i = 0; i < size; i++) {
        start = lst;
        if (lst || lst->next) {
            while (start->next) {
                if (cmp(start->data, start->next->data)) {
                    swap(start, start->next);
                }
                start = start->next;
            }
        }
    }
    return lst;
}

static void swap(t_list *n1, t_list *n2) {
    void *tmp = n1->data;
    n1->data = n2->data;
    n2->data = tmp;
}
