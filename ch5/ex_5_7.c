#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_SIZE 1000
#define MAX_TOTAL_LINE_SIZE 10000

char *lineptrs[MAX_LINES];

int agetline(char *buf, int lim) {
    int i = 0;
    char c;
    lim--;  // take lim to mean inclusive of EOF
    while(lim-- > 0 && (c = getchar()) != EOF && c != '\n') {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return i;
}

int readlines(char *ptrs[], char *dst, int line_lim, int line_length_lim, int dst_lim) {
    int l = 0, offset = 0, nlines = 0;
    char buf[line_length_lim];

    while (nlines < line_lim && (l = agetline(buf, line_length_lim))) {
        l++;
        if (l + offset > dst_lim) {
            break;
        }
        strcpy(dst + offset, buf);
        ptrs[nlines++] = dst+offset;
        offset += l;
    }
    return (nlines == 0 || nlines == line_lim) ? 0: nlines;
}

void writelines(char *ptrs[], int nlines) {
    while (nlines-- > 0) {
        printf("%s\n", *ptrs++);
    }
}

void swap(char *v[], int i, int j) {
    char *tmp;
    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right) return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i<= right; i++) {
        if (strcmp(v[i], v[left]) < 0) swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int main() {
    char buffer[MAX_TOTAL_LINE_SIZE];
    int nlines;

    if ((nlines=readlines(lineptrs, buffer, MAX_LINES, MAX_LINE_SIZE, MAX_TOTAL_LINE_SIZE))) {
        qsort(lineptrs, 0, nlines - 1);
        writelines(lineptrs, nlines);
        return 0;
    }
    return 0;
}
