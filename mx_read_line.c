#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
    static char *remainder = NULL;
    char buf[buf_size + 1];
    int read_bytes = 0;
    int delim_index = -1;
    char *tmp_str = NULL;
    char *tmp = NULL;
    if (remainder) {
        tmp_str = mx_strdup(remainder);
    }

    while ((read_bytes = read(fd, buf, buf_size)) >= 0) {
        buf[read_bytes] = '\0';
        tmp = mx_strjoin(tmp_str, buf);
        mx_strdel(&tmp_str);
        tmp_str = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(tmp_str, delim);
        if (delim_index != -1) {
            tmp_str[delim_index] = '\0';
            if (remainder) {
                mx_strdel(&remainder);
            }
            remainder = mx_strdup(tmp_str + delim_index + 1);
            break;
        }
        if (read_bytes == 0) {
            if (remainder) {
                mx_strdel(&remainder);
            }
            break;
        }
    }
    if (read_bytes == -1) {
        return -1;
    }
    *lineptr = mx_strdup(tmp_str);
    mx_strdel(&tmp_str);
    return mx_strlen(*lineptr);
}
