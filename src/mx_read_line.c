#include "libmx.h"

static char *get_leaving(int buf_size, char delim, const int fd)
{
    char *tmp = NULL;
    char *result_str = NULL;
    char buffer[buf_size + 1];
    int read_result = 0;
    int delim_index;

    while ((read_result = read(fd, buffer, buf_size)) > 0)
    {
        buffer[read_result] = '\0';
        tmp = mx_strjoin(result_str, buffer);
        mx_strdel(&result_str);
        result_str = mx_strdup(tmp);
        mx_strdel(&tmp);
        delim_index = mx_get_char_index(result_str, delim);
        if (delim_index >= 0)
            break;
    }
    return result_str;
}

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd)
{
    if (fd < 0 || fd > 4096 || buf_size <= 0 || read(fd, 0, 0) < 0)
        return -1;

    static char *leavings[4096];
    char *last_leaving = get_leaving(buf_size, delim, fd);
    if (!last_leaving)
        return 0;
    char *tmp = mx_strjoin(leavings[fd], last_leaving);
    int delim_index = mx_get_char_index(tmp, delim);

    tmp[delim_index] = '\0';
    leavings[fd] = mx_strdup(tmp + delim_index + 1);
    *lineptr = mx_strdup(tmp);
    mx_strdel(&tmp);
    return mx_strlen(*lineptr);
}
