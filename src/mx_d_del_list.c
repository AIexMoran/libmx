#include "libmx.h"

void mx_d_del_list(t_d_list **list) {
    while (*list) {
        mx_d_pop_back(list);
    }
}
