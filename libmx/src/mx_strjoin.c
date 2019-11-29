#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    if (s1 == NULL)
        return mx_strdup(s2);
    if (s2 == NULL)
        return mx_strdup(s1);
    else {
        char *str1 = mx_strdup(s1);
        char *str2 = mx_strdup(s2);
        char *s = mx_strcat(str1, str2);

        mx_strdel(&str2);
        return s;
    }
}
