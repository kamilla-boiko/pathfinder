#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -2;
    }
    int i = 0;
    int j = 0;
    while(str[i] != '\0') {
        if (str[i] == sub[j]) {
            while (str[i] == sub[j]) {
                i++;
                j++;
                if (sub[j] == '\0') {
                   return i - j;
                }    
            }
        }
        i++;
    }
    return -1;
}
