#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

int main() {
    int k = 0;
    for (; k < 25; k += 1) {
        int x;
        scanf("%d", &x);
        if (x) break;
    }
    int x = k % 5;
    int y = k / 5;
    printf("%d\n", abs(x - 2) + abs(y - 2));
}
