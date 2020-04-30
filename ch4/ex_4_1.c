#include <stdio.h>
#include <assert.h>

int strrindex(char s[], char t[]) {
    // of course would be faster if going from right to left
    int i, j, k, l = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++);
        if (k > 0 && t[k] == '\0') l = i;
    }
    return l;
}


int main() {
    assert(strrindex("aaaa", "a") == 3);
    assert(strrindex("testtest", "test") == 4);
    assert(strrindex("abcdef", "abd") == -1);
    return 0;
}
