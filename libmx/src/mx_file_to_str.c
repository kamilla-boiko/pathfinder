#include "libmx.h"

char *mx_file_to_str(const char *file) {
    if (!file) return NULL;
    int count = 0;
    char buf[1];
    int fd = open(file, O_RDONLY);
    if (fd < 0) return NULL;
    int read_bytes = read(fd, buf, sizeof(buf));
    if (read_bytes <= 0) return NULL;
    while (read_bytes > 0) {
    	count++;
    	read_bytes = read(fd, buf, sizeof(buf));
    }
    close(fd);
    fd = open(file, O_RDONLY);
    char *s = mx_strnew(count);
    char *str = s;
    int bytes = read(fd, buf, sizeof(buf));
    while (bytes > 0) {
    	*s = *buf;
    	bytes = read(fd, buf, sizeof(buf));
    	s++;
    }    
    close(fd);
    return str;
}
