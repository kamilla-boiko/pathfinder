#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
   if (s == NULL) {
       return NULL;
   }
   int size_arr = mx_count_words(s, c);
   char **arr = malloc((size_arr + 1) * sizeof(char *));
   for (int i = 0; i < size_arr; i++) {
       while (*s == c) {
           s++;
       }
       int size_str = mx_strlen_my(s, c);
       arr[i] = mx_strnew(size_str);
       for(int j = 0; *s != c; j++) {
           arr[i][j] = *s;
           s++;
       }
   }
   arr[size_arr] = NULL;
   return arr;
}
