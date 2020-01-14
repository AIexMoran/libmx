#include "libmx.h"

int mx_strlen(const char *str);
char *mx_strcpy(char *dst, const char *src);

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *save = s1;
    
    s1 += mx_strlen(s1);
    mx_strcpy(s1, s2);
    return save;
}
