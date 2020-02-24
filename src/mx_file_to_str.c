#include "libmx.h"

static void append(char **result, char *buf) {
    char *tmp_str = mx_strjoin(*result, buf);

    mx_strdel(result);
    *result = mx_strdup(tmp_str);
    mx_strdel(&tmp_str);
}

char *mx_file_to_str(const char *file) {
    int f_d = 0;
    int read_bytes = 0;
    char buf[128];
    char *result = NULL;

    f_d = open(file, O_RDONLY);
    if (f_d < 0)
        return NULL;
    while ((read_bytes = read(f_d, buf, sizeof(buf) - 1)) > 0) {
        buf[read_bytes] = '\0';
        append(&result, buf);
    }
    if (close(f_d) < 0) {
        return NULL;
    }
    return result;
}
