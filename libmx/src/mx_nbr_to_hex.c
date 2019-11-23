#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    int size = 0;
    unsigned long newnbr = nbr;
    if (nbr == 0) {
        char *s = mx_strnew(1);
        s[0] = 48;
        return s;    
    }
    while (newnbr) {
        newnbr = newnbr / 16;
        size++;
    }
    char *hex = mx_strnew(size);
    for (int i = size - 1; i >= 0; i--) {
        hex[i] = nbr % 16;
        if (hex[i] <= 9) {
            hex[i] = hex[i] + 48;
        }
        else if (hex[i] > 9) {
            hex[i] = hex[i] + 87;
        }
        nbr = nbr / 16;
    }
    return hex;
}
