#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, 
                const void *little, size_t little_len) {
    unsigned int j = 1;
    unsigned char *b = (unsigned char *)big;
    unsigned char *l = (unsigned char *)little;
    unsigned char *cb = NULL;
    unsigned char *cl = NULL;

    for (unsigned int i = 0; *b != '\0' && i < big_len; i++) {
        if(*b == *l) {
            cb = b;
            cl = l;
            while (*cb == *cl && j < little_len) {
                cb++;
                cl++;
                j++;
            }
            if (j == little_len && *cb == *cl)
                return b;
        }
        b++;
    }      
    return NULL;
}
