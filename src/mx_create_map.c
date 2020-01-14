#include "libmx.h"

t_map *mx_create_map(size_t size) {
    t_map *map = malloc(sizeof(t_map));

    map->nodes = malloc(size * sizeof(t_node *));
    for (size_t i = 0; i < size; i++) {
        map->nodes[i] = NULL;
    }
    map->size = size;
    return map;
}
