#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _++) {
        int x, y;
        scanf("%d %d", &y, &x);

        for (int i = 0; i < y; i += 1) {
            for (int j = 0; j < x; j += 1) {
                if ((((i + 1) / 2) ^ ((j + 1) / 2)) & 1)
                    printf("0 ");
                else
                    printf("1 ");

            }
            printf("\n");
        }
    }
}