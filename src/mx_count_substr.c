#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle);
int mx_strlen(const char *str);

int mx_count_substr(const char *str, const char *sub) {
    if (!str || !sub) {
        return -1;
    }
    int result = 0;
    int length = mx_strlen(sub);
    char *sub_str = mx_strstr(str, sub);

    if (!length) {
        return 0;
    }
    if (sub_str && *str) {
        result++;
        sub_str += length == 0 ? 1 : length;
    }
    else {
        return 0;
    }
    return result + mx_count_substr(sub_str, sub);
}
