#include <stdio.h>
#include <cmath>

double invfact(int n) {
    double result = 1;
    for (int i = 1; i <= n; i += 1)
        result /= i;
    return result;
}

int main() {
    const double A = -1;
    const double B = 1;
    const double DELTA = 1e-1;
    const double EPS = 1e-3;

    printf("     x    |   s(x)   |   f(x)   \n");
    for (double x = A; x < B + DELTA / 2; x += DELTA) {
        double result = 0;
        for (int i = 0;; i += 1) {
            double item = (1 - 2 * (i % 2)) * pow(x, 2. * i) * invfact(2 * i);
            result += item;
            if (fabs(item) < EPS) {
                break;
            }
        }
        printf(" %8.4lf | %8.4lf | %8.4lf \n", x, result, cos(x));
    }
}

