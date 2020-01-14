#include "libmx.h"

static void put_value(t_node **node, char *key, void *value);

void mx_put_map(t_map **map, char *key, void *value) {
    int index = ((*map)->size - 1) & mx_hash(key);

    put_value(&(*map)->nodes[index], key, value);
}

static void put_value(t_node **node, char *key, void *value) {
    while (*node) {
        *node = (*node)->next;
    }
    *node = malloc(sizeof(t_node));
    (*node)->data = value;
    (*node)->key = mx_strdup(key);
}
