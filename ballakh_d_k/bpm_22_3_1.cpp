#include<stdio.h>
#include<math.h>

#define eps 1e-4

#define XMIN 0.1
#define XMAX 1.0
#define DX 0.05

double fact(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i += 1)
        result *= i;
    return result;
}

void _main() {
    printf("+-----------+-----------+\n");
    printf("|     x     |    sum    |\n");
    printf("+-----------+-----------+\n");
    for (double x = XMIN; x <= XMAX + DX / 2; x += DX) {
        double sum = 0.0;
        for (int i = 0; ; i += 1) {
            double ds = pow(2 * x, i) / fact(i);
            sum += ds;
            if (ds < eps)
                break;
        }
        printf("| %.7lf | %.7lf |\n", x, sum);
    }
    printf("+-----------+-----------+\n");
}

int main() {
    _main();
}
