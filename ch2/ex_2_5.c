#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) return i;
        }
    }
    return -1;
}

int any_fast(char s1[], char s2[]) {
    char seen[256];
    for (int k = 0; k < 256; k++) {
        seen[k] = 0;
    }

    for (int j = 0; s2[j] != '\0'; j++) {
        seen[s2[j]] = 1;
    }

    for (int i = 0; s1[i] != '\0'; i++) {
        if (seen[s1[i]]) return i;
    }

    return -1;
}

int main() {
    char source[] = "abcdef";
    char search[] = "d";
    printf("%s %s %d\n", source, search, any(source, search));
    printf("%s %s %d", source, search, any_fast(source, search));

    return 0;
}
