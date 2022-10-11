// https://codeforces.com/problemset/problem/136/b

#include <stdio.h>

#define MAX3DIGITS 19

int get_digit(int n, int k) {
    for (int i = 0; i < k; i += 1)
        n /= 3;
    return n % 3;
}

int pow3(int n) {
    int res = 1;
    for (int i = 0; i < n; i += 1)
        res *= 3;
    return res;
}

int main() {
    int a; int c;
    int result = 0;
    scanf("%d %d", &a, &c);

    for (int i = 0; i < MAX3DIGITS; i += 1) {
        int da = get_digit(a, i);
        int dc = get_digit(c, i);
        result += pow3(i) * ((dc - da + 3) % 3);
    }

    printf("%d\n", result);
}
