#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) return NULL;
    char *trim = mx_strtrim(str);
    int i = 0;
    int count = 0;
    while (trim[i] != '\0') {
    	if (mx_isspace(trim[i]) == 1) {
    		i++;
    		count++;
    		while (mx_isspace(trim[i]) == 1) {
    			i++;
    		}
    	}
    	else {
    		i++;
    		count++;
    	}
    }
    char *s = mx_strnew(count);
    int j = 0;
    int h = 0;
    while (trim[j] != '\0') {
    	if (mx_isspace(trim[j]) == 1) {
    		s[h] = ' ';
    		h++;
    		j++;
    		while (mx_isspace(trim[j]) == 1) {
    			j++;
    		}
    	}
    	else {
    		s[h] = trim[j];
    		j++;
    		h++;
    	}
    }
    return s;
}
