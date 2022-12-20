#include<stdio.h>
#include<math.h>
#include<assert.h>

struct Matrix {
    double a;
    double b;
    double c;
    double d;
};

double det(Matrix m) {
    return m.a * m.d - m.b * m.c;
}

Matrix inverse(Matrix m) {
    double D = det(m);
    return Matrix{m.d / D, -m.b / D, -m.c / D, m.a / D};
}

Matrix mul(Matrix m1, Matrix m2) {
    return Matrix{
        m1.a * m2.a + m1.b * m2.c,
        m1.a * m2.b + m1.b * m2.d,
        m1.c * m2.a + m1.d * m2.c,
        m1.c * m2.b + m1.d * m2.d,
    };
}

Matrix add(Matrix m1, Matrix m2) {
    return Matrix{
        m1.a + m2.a,
        m1.b + m2.b,
        m1.c + m2.c,
        m1.d + m2.d,
    };
}
Matrix sub(Matrix m1, Matrix m2) {
    return Matrix{
        m1.a - m2.a,
        m1.b - m2.b,
        m1.c - m2.c,
        m1.d - m2.d,
    };
}

#define print_matrix(m) \
    printf("(%.2lf %.2lf)\n",   m.a, m.b); \
    printf("(%.2lf %.2lf)\n\n", m.c, m.d);

void _main() {
    Matrix e = {1, 0, 0, 1};

    double eps = 1.0/0.0;
    scanf("%lf", &eps);

    int n = -1;
    scanf("%d", &n);

    Matrix a;
    scanf("%lf %lf %lf %lf", &a.a, &a.b, &a.c, &a.d);


    Matrix m = e;
    print_matrix(m);

    for (int i = 1; i < n; i += 1) {
        m = mul(m, sub(add(e, e), mul(a, m)));
        print_matrix(m);
        printf("det = %lf\n", det(m));

        if (abs(det(m) - 1) <= eps)
            break;
    }


}

int main() {
    _main();
}
