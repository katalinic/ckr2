#include <stdio.h>
#include <assert.h>
#include <string.h>

void reverse(char s[], int i, int j) {
    if (i >= j) return;
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
    reverse(s, i+1, j-1);
}

int main() {
    char buf[] = "aabcda";
    reverse(buf, 0, strlen(buf) - 1);
    assert(!strcmp(buf, "adcbaa"));
    return 0;
}
