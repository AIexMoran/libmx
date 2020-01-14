#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int result = 0;
    int length = mx_strlen(sub);
    char *sub_str = mx_strstr(str, sub);

    if (!str || !sub) {
        return -1;
    }
    if (!length) {
       return 0;
    }
    if (sub_str && *str) {
        result++;
        sub_str += length;
    }
    else {
        return 0;
    }
    return result + mx_count_substr(sub_str, sub);
}
