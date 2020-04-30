#include <stdio.h>
#include <string.h>

#define MAX_LINE (1000)

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: file1 file2\n");
        return 1;
    }

    char *file1 = argv[1], *file2 = argv[2];
    FILE *fp1, *fp2;

    if ((fp1 = fopen(file1, "r")) == NULL) {
        printf("Failed to open file %s\n", file1);
        return 1;
    }
    if ((fp2 = fopen(file2, "r")) == NULL) {
        printf("Failed to open file %s\n", file2);
        fclose(fp1);
        return 1;
    }

    char line1[MAX_LINE], line2[MAX_LINE];

    while ((fgets(line1, MAX_LINE, fp1)) != NULL &&
           (fgets(line2, MAX_LINE, fp2)) != NULL &&
            !strcmp(line1, line2));

    fclose(fp1);
    fclose(fp2);
    if (line1 != NULL) {
        printf("---- File %s ----\n", file1);
        printf("%s\n", line1);
    }
    if (line2 != NULL) {
        printf("---- File %s ----\n", file2);
        printf("%s\n", line2);
    }

    return 0;
}
