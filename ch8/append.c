#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE (1024)

int main(int argc, char *argv[]) {
    int n, fd_to, fd_from;
    long l;
    char buf[BUF_SIZE];

    if (argc < 3) {
        return 1;
    }
    if ((argc--, fd_to = open(*++argv, O_RDWR, 0)) == -1) {
        return 1;
    }
    if ((l = lseek(fd_to, 0, 2)) == -1) {
        return 1;
    }

    while (argc-- > 0 && (fd_from = open(*++argv, O_RDONLY, 0)) > -1) {
        while ((n = read(fd_from, buf, BUF_SIZE)) > 0) {
            write(fd_to, buf, n);
        }
        close(fd_from);
    }
    close(fd_to);
    return 0;
}
