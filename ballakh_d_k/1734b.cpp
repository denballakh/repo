#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _ += 1) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i += 1) {
            for (int j = 1; j <= i; j += 1) {
                if (j == 1 || j == i)
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
        printf("\n");
    }
}
