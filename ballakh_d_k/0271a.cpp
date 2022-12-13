#include <stdio.h>

bool unique(int n, int base = 10) {
    int digits[10] = {};
    while (n) {
        digits[n % 10]++;
        n /= 10;
    }
    for (int i = 0; i < 10; i++)
        if (digits[i] > 1)
            return false;
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    n++;
    for (;; n++)
        if (unique(n)) {
            printf("%d\n", n);
            return 0;
        }
}
