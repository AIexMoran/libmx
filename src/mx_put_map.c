#include "libmx.h"

static void put_value(t_node **node, char *key, void *value) {
    t_node *new_node = NULL;
    t_node *last = NULL;
    t_node *tmp = NULL;

    for (tmp = *node; tmp; tmp = tmp->next) {
        if (!mx_strcmp(tmp->key, key)) {
            free(tmp->data);
            tmp->data = value;
            return;
        }
        last = tmp;
    }
    new_node = malloc(sizeof(t_node));
    new_node->data = value;
    new_node->key = key;
    new_node->next = NULL;
    if (last)
        last->next = new_node;
    else
        *node = new_node;
}

void mx_put_map(t_map **map, char *key, void *value) {
    unsigned int index = mx_hash(key) % (*map)->size;

    put_value(&(*map)->nodes[index], key, value);
}
