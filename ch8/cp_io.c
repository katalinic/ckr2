#include <unistd.h>

#define BUF_SIZE (1024)

int main() {
    char buf[BUF_SIZE];
    int n;

    while ((n = read(0, buf, BUF_SIZE)) > 0) {
        write(1, buf, n);
    }

    return 0;
}
