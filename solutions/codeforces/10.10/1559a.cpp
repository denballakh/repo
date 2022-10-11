// https://codeforces.com/problemset/problem/1559/A

#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _ += 1) {
        int n; int s = ~0;
        scanf("%d", &n);
        for (int i = 0; i < n; i += 1) {
            int x;
            scanf("%d", &x);
            s &= x;
        }

        printf("%d\n", s);
    }
}
