#include "pathfinder.h"

void mx_not_exist_or_empty(char *argv) {
    int fd = open(argv, O_RDONLY);
    char buf;
    int num = read(fd, &buf, 1);

    if (fd < 0) {
        write(2, "error: file ", 12);
        write(2, argv, mx_strlen(argv));
        write(2, " does not exist\n", 16);
        close(fd);
        exit(0);
    }
    else if (num <= 0) {
        write(2, "error: file ", 12);
        write(2, argv, mx_strlen(argv));
        write(2, " is empty\n", 10);
        close(fd);
        exit(0);
    }
}
