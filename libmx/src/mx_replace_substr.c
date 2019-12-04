#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) 
        return NULL;
    int len_str = mx_strlen(str);
    int len_sub = mx_strlen(sub);
    int len_per = mx_strlen(replace);
    int diff = len_sub - len_per;

    if (diff < 0)
        diff = -diff;
    char *res = mx_strnew(len_str + mx_count_substr(str, sub) * diff);
    
    for (int i = 0, k = 0; i < len_str; i++) {
        if (!mx_get_substr_index(&str[i], sub)) {
            for (int j = 0; j < len_per; j++, k++)
                res[k] = replace[j];
            i = i + len_sub - 1;
        } 
        else
            res[k++] = str[i];
    }
    return res;
}
