#include "libmx.h"

void mx_del_map(t_map **map) {
    t_map *m = *map;

    if (!m)
        return;
    for (size_t i = 0; i < m->size; i++) {
        if (m->nodes[i]) {
            free(m->nodes[i]->data);
            free(m->nodes[i]->key);
            free(m->nodes[i]);
        }
    }
    free(m->nodes);
    free(m);
    map = NULL;
}
