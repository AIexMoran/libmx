#include "libmx.h"

static void put_value(t_node **node, char *key, void *value);

void mx_put_map(t_map **map, char *key, void *value) {
    int index = mx_hash(key) % (*map)->size;

    put_value(&(*map)->nodes[index], key, value);
}

static void put_value(t_node **node, char *key, void *value) {
    t_node *new_node = malloc(sizeof(t_node));

    new_node->data = value;
    new_node->key = mx_strdup(key);
    new_node->next = NULL;
    while (*node) {
        if (!(*node)->next) {
            (*node)->next = new_node;
            return;
        }
        *node = (*node)->next;
    }
    *node = new_node;
}
