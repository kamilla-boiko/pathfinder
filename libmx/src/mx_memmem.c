#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned int i = 0;
    unsigned int j = 1;
    unsigned char *b = (unsigned char *)big;
    unsigned char *l = (unsigned char *)little;
    while (*b != '\0' && i < big_len) {
        if(*b == *l) {
            unsigned char *cb = b;
            unsigned char *cl = l;
            while (*cb == *cl && j < little_len) {
                cb++;
                cl++;
                j++;
            }
            if (j == little_len && *cb == *cl) {
                return b;
            }
        }
        i++;
        b++;
        
    }      
    return NULL;
}
