#include <stdio.h>

int count_ones(int n) {
    int count = 0;
    while (n) {
        count += 1;
        n &= n - 1;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", count_ones(n));
}
