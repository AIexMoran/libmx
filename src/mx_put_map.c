#include "libmx.h"

static void put_value(t_node *node, char *key, void *value);

void mx_put_map(t_map **map, char *key, void *value) {
    int index = mx_hash(key) % (*map)->size;

    put_value((*map)->nodes[index], key, value);
}

static void put_value(t_node *node, char *key, void *value) {
    t_node *new_node = NULL;

    while (node) {
        if (!mx_strcmp(node->key, key)) {
            free(node->data);
            node->data = value;
            break;
        }
        if (!node->next) {
            new_node = malloc(sizeof(t_node));
            new_node->data = value;
            new_node->key = key;
            new_node->next = NULL;
            node->next = new_node;
            break;
        }
        node = node->next;
    }
}
