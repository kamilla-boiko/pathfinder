#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }
    int i = 0;
    int j = 0;
    int count = 0;
    while(str[i] != '\0') {
        if(str[i] == sub[j]) {
            while(str[i] == sub[j]) {
                i++;
                j++;
                if(sub[j] == '\0'){
                    j = 0;
                    count++;
                }
            }
        }
        i++;
    }
    return count;
}
