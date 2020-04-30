#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE (1024)

int main(int argc, char *argv[]) {
    int n, fd_from, fd_to;
    char buf[BUF_SIZE];

    if (argc != 3) {
        printf("Usage: from to\n");
        return 1;
    } else if ((fd_from = open(argv[1], O_RDONLY, 0)) == -1) {
        printf("Failed to open %s\n", argv[1]);
        return 1;
    } else if ((fd_to = creat(argv[2], 0666)) == -1) {
        printf("Failed to create %s\n", argv[2]);
        return 1;
    }

    while ((n = read(fd_from, buf, BUF_SIZE)) > 0) {
        if (write(fd_to, buf, n) != n) {
            printf("Write error to %s\n", argv[2]);
        }
    }

    return 0;
}
