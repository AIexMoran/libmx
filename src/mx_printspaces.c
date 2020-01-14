#include "libmx.h"

void mx_printspaces(int spaces) {
    for (int i = 0; i < spaces; i++) {
        mx_printstr(" ");
    }
}
