#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    int start = 0;
    int end = mx_strlen(str);
    int i = 0;
    while (mx_isspace(str[i]) == 1) {
        i++;
    }
    start = i;
    int j = end - 1;
    while (mx_isspace(str[j]) == 1) {
        j--;
    }
    end = j;
    char *trim = mx_strnew(j - i + 1);
    int k = 0;
    while (i <= j) {
        trim[k] = str[i];
        k++;
        i++;
    }
    return trim; 
}
