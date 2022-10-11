#include <stdio.h>
#include <cmath>

double invfact(int n) {
    double result = 1;
    for (int i = 1; i <= n; i += 1)
        result /= i;
    return result;
}

int main() {
    const double A = 0;
    const double B = 1;
    const double DELTA = 0.1;
    const double EPS = 1e-4;

    printf("     x    |   s(x)   |   f(x)   \n");
    for (double x = A; x < B + DELTA / 2; x += DELTA) {
        double result = 0;
        for (int i = 0;; i += 1) {
            double item = pow(2 * x, i) * invfact(i);
            result += item;
            if (fabs(item) < EPS) {
                break;
            }
        }
        double actual_value = exp(2 * x);
        printf(" %8.4lf | %8.4lf | %8.4lf \n", x, result, actual_value);
    }
}

