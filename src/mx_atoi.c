#include "libmx.h"

static bool isvalid_char(char c) {
    return mx_isspace(c) || c == '-' || c == '+';
}

int mx_atoi(const char *str) {
    int result = 0;
    int i = 0;
    int sign = 0;

    while (!mx_isdigit(str[i])) {
        if (!isvalid_char(str[i]))
            return 0;
        i++;
    }
    sign = str[i - 1] == '-' ? -1 : 1;
    while (mx_isdigit(str[i])) {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result * sign;
}
