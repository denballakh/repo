#include <stdio.h>

int main() {
    int a, m;
    scanf("%d %d", &a, &m);
    for (int _ = 0; _ < 30000; _++) {
        a *= 2;
        a %= m;
        if (!a) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}
