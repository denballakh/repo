#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int gifts[n] = {};
    for (int i = 0; i < n; i += 1) {
        int x;
        scanf("%d", &x);
        gifts[x - 1] = i + 1;
    }
    for (int i = 0; i < n; i += 1) {
        printf("%d ", gifts[i]);
    }
}
