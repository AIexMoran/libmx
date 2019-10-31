#include "libmx.h"

int mx_count_substr(const char *str, const char *sub);
int mx_strlen(const char *str);
int mx_get_substr_index(const char *str, const char *sub);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strndup(const char *str, size_t n);
void mx_strdel(char **str);

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }
    int subs = mx_count_substr(str, sub);
    int subs_length = mx_strlen(sub) * subs;
    int replace_length = mx_strlen(replace) * subs;
    int str_length = mx_strlen(str) - subs_length;
    int index = 0;
    char *result = mx_strnew(str_length + replace_length);
    char *tmp = NULL;

    while ((index = mx_get_substr_index(str, sub)) != -1) { 
        tmp = mx_strndup(str, index);
        mx_strcat(result, tmp);
        mx_strcat(result, replace);
        str += index + mx_strlen(sub);
        mx_strdel(&tmp);
    }
    mx_strcat(result, str);
    return result;
}
