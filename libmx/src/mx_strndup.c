#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *s = mx_strncpy(mx_strnew(mx_strlen(s1)), s1, n);
    return s;
}
