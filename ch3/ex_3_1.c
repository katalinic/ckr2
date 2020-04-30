#include <stdio.h>
#include <assert.h>

int binary_search(int v[], int x, int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low < high) {
        mid = (low + high)/2;
        if (x <= v[mid]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return (x == v[low])? low : -1;
}

int main() {
    int arr[6] = {0, 1, 3, 4, 6, 7};
    assert(binary_search(arr, 4, 6) == 3);
    return 0;
}
