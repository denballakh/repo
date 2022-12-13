#include <stdio.h>
#include <cmath>


int main() {
    const double A = 0;
    const double B = 1;
    const double DELTA = 0.05;
    const double EPS = 1e-3;

    printf("     x    |   s(x)   |   f(x)   \n");
    for (double x = A; x < B + DELTA / 2; x += DELTA) {
        double result = 0;
        for (int i = 1;; i += 1) {
            double item = pow(x, i) * (i % 2) * (2 - i % 4);
            result += item;
            if (fabs(item) < EPS) {
                break;
            }
        }
        double actual_value = x;
        printf(" %8.4lf | %8.4lf | %8.4lf \n", x, result, actual_value);
    }
}

