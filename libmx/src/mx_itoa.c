#include "libmx.h"

char *mx_itoa(int number) {
    char *str;
    int n = number;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        count++;
    }
    if (number < 0) {
        str = mx_strnew(count + 1);
        str[0] = '-';
        number = number * -1;
        while (number != 0) {
            str[count] = number % 10 + 48;
            count--;
            number = number / 10;
        }
    }
    else {
        str = mx_strnew(count);
        while (number != 0) {
            str[count - 1] = number % 10 + 48;
            count--;
            number = number / 10;
        }
    }
    return str;
}
