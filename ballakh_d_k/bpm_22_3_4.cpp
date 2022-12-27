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


Matrix mul(Matrix m1, Matrix m2) {
    return Matrix{
        m1.a * m2.a + m1.b * m2.c,
        m1.a * m2.b + m1.b * m2.d,
        m1.c * m2.a + m1.d * m2.c,
        m1.c * m2.b + m1.d * m2.d,
    };
}

Matrix mul(Matrix m1, double x) {
    return Matrix{
        m1.a * x,
        m1.b * x,
        m1.c * x,
        m1.d * x,
    };
}

Matrix inverse(Matrix m) {
    return mul(Matrix{m.d, -m.b, -m.c, m.a}, 1.0 / det(m));
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
    printf("(% .3lf % .3lf)\n", m.a, m.b); \
    printf("(% .3lf % .3lf)\n", m.c, m.d);

void _main() {
    Matrix e = {1, 0, 0, 1};

    // double eps = 1.0/0.0;
    // scanf("%lf", &eps);

    // int n = -1;
    // scanf("%d", &n);

    // Matrix a;
    // scanf("%lf %lf %lf %lf", &a.a, &a.b, &a.c, &a.d);

    double eps = 0.001;
    int n = 10;
    Matrix a {
        0, 2,
        2, 0,
    };




    double d = det(a);

    printf("|A| = %lf\n", d);
    if (abs(d) > 1 && 0) {
        a = mul(a, 1.0 / sqrt(abs(d)));
        printf("A* =\n");
        print_matrix(a);
    }

    Matrix m = e;

    for (int i = 1; i < n; i += 1) {
        m = mul(m, sub(mul(e, 2), mul(a, m)));
        printf("M =\n");
        print_matrix(m);
        printf("|A M| = %lf\n", det(mul(a, m)));

        if (abs(det(mul(a, m)) - 1) <= eps)
            break;
    }
    if (abs(d) > 1 && 0) {
        a = mul(a, sqrt(abs(d)));
        m = mul(m, 1.0 / sqrt(abs(d)));
    }

    printf("\n");
    print_matrix(a);
    printf("^-1 == \n");
    print_matrix(m);
    printf("==\n");
    print_matrix(inverse(a));

}

int main() {
    _main();
}
