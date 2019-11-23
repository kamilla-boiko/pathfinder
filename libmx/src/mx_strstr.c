#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    while(*haystack) {
        if(*haystack == *needle) {
            int i = 0;
            while(haystack[i] == needle[i]) {
                i++;
            }
            if(needle[i] == '\0') {
                return (char*)haystack;
            }
        }
        haystack++;
    }
    return NULL;
}
