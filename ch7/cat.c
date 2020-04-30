#include <stdio.h>

void fcopy(FILE *from, FILE *to) {
    int c;
    while ((c = getc(from)) != EOF) {
        putc(c, to);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *fname;

    while ((fname = *argv++) != NULL) {
        fp = fopen(fname, "r");
        if (fp != NULL) {
            fcopy(fp, stdout);
            fclose(fp);
        }
    }

    return 0;
}
