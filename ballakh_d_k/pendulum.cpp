#include <stdio.h>
#include "point.cpp"

#define write_f(file, var) fwrite(&(var), sizeof(var), 1, file)
#define DUMP_STATE \
    write_f(file, t); \
    write_f(file, r.x); \
    write_f(file, r.y); \
    write_f(file, v.x); \
    write_f(file, v.y); \
    write_f(file, a.x); \
    write_f(file, a.y); \
    printf(".");

void simulation1(Point<> r0, Point<> v0, double g, double dt, int iterations = -1) {
    FILE* file = fopen("./data.bin", "wb");

    Point<> r = r0;
    Point<> v = v0;
    Point<> a(0.0, 0.0);
    double t = 0;
    DUMP_STATE;

    for (; iterations; iterations < 0 ? 0 : iterations -= 1) {
        a = -r / r.norm() / r.norm() / r.norm() * g;
        if (
            (r.norm() < v.norm() * dt * 3)
            && (r.dot(v) < 0)
        ) {
            auto v_ = v;
            auto r_ = r;

            v = Point(0.0, 0.0);
            r = Point(0.0, 0.0);
            t += r_.norm() / v_.norm();
            DUMP_STATE;

            v = v_ * -1;
            r = r_;
            t += r_.norm() / v_.norm();
            DUMP_STATE;

            r = r + v * dt;
            v = v + a * dt;
            t += dt;
            DUMP_STATE;

        } else {
            v = v + a * dt;
            r = r + v * dt;
            t += dt;
            DUMP_STATE;
        }
    }
}


int main() {
    // simulation1(Point(1.0, 0.0), Point(0.0, 1.0), 1.0, 0.01, 1000); // circle
    // simulation1(Point(1.0, 1.0), Point(1.0, 0.0), 1.0, 0.01, 5000); // ellipse
    simulation1(Point(1.0, 1.0), Point(0.0, 0.0), 1.0, 0.01, 600); // line
    // simulation1(Point(1.0, 1.0), Point(0.0, 0.0), 1.0, 0.001, 6000); // line 2
}
