#include "libmx.h"

char *mx_strnew(const int size);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_strdup(const char *str);
void mx_strdel(char **str);

char *mx_file_to_str(const char *file) {
    int file_descriptor = 0;
    int size_read = 0;
    int size_file = 0;
    char buf[128];
    char *result = NULL;
    char *tmp_str = NULL;

    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor < 0) {
        return NULL;
    }
    while ((size_read = read(file_descriptor, buf, sizeof(buf) - 1)) > 0) {
        buf[size_read] = '\0';
        size_file += size_read;
        tmp_str = mx_strjoin(result, buf);
        mx_strdel(&result);
        result = mx_strdup(tmp_str);
        mx_strdel(&tmp_str);
    }
    if (close(file_descriptor) < 0) {
        return NULL;
    }

    return result;
}
