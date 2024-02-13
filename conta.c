#include <stdio.h>

int conta(int a[], int l, int x, int y) {
    if (l <= 1) {
        return l == 1 && a[0] == x ? 0 : -1;  
    }

    int n = conta(a + 1, l - 1, x ,y);

    if (l > 1) {
        if (a[0] == x) {
            if (a[1] == y) {
                return n == -1 ? 1 : n + 1;
            } else {
                return n == -1 ? 0 : n;
            }
        } else {
            return n;
        }
    }
}

int main() {
    int a[] = {2, 3, 5, 4, 3, 5, 6, 4, 3, 3, 1, 2, 3};

    printf("%d", conta(a, sizeof(a) / sizeof(a[0]), 1, 3));
}