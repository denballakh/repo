#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))

int main() {
    int n, k;
    int ans = -2000000001;
    scanf("%d %d", &n, &k);
    for (int _ = 0; _ < n; _ += 1) {
        int f, t;
        scanf("%d %d", &f, &t);
        ans = max(ans, min(f, f - t + k));
    }
    printf("%d\n", ans);
}
