#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE (1024)

int main(int argc, char *argv[]) {
    int n, fd;
    char buf[BUF_SIZE];

    while (--argc > 0 && (fd = open(*++argv, O_RDONLY, 0)) > -1) {
        while ((n = read(fd, buf, BUF_SIZE)) > 0) {
            write(1, buf, n);
        }
        close(fd);
    }

    return 0;
}
