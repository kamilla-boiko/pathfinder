#include "libmx.h"

void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d = dst;
    const unsigned char *s = src;
    unsigned int i = 0;
    while(i < n) {
      *d = *s;
      i++;
      if (*s == c) {
         return dst;
      }
      d++;
      s++;
    }
    return dst;
}
