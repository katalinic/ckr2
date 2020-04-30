#include <stdio.h>
#include <string.h>

void squeeze(char s1[], const char s2[]) {
    int r, w;
    char found;
    for (r = w = 0; s1[r] != '\0'; r++) {
        found=0;
        for (int k = 0; k < strlen(s2); k++) {
            if (s1[r] == s2[k]) {
                found=1;
                break;
            }
        }
        if (!found) {
            s1[w++] = s1[r];
        }
    }
    s1[w] = '\0';
}

int main() {
    char s1[] = "abcdefgh";
    char s2[] = "adg";
    squeeze(s1, s2);
    printf("Post squeeze: %s", s1);
    return 0;
}
