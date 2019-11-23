#include "libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != c) {
            count++;
            while(str[i] != c && str[i] != '\0') {
                i++;
            }
        }
        if (str[i] == c) {
            i++;
        }
    }
    return count;
}
