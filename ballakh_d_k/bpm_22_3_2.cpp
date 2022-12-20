#include<stdio.h>
#include<math.h>

bool is_inside(double x, double y) {
    if (x < -2) return false;
    if (x > +2) return false;
    if (y < -1) return false;
    if (y > +1) return false;
    if (x * x + y * y < 1) return false;
    return true;
}

void _main(FILE* file) {
    int count[2] = {0, 0};

    while (1) {
        double x, y;
        if (fscanf(file, "%lf %lf", &x, &y) == -1) break;
        count[is_inside(x, y)] += 1;
        // printf("current point: %lf %lf hit?: %d hits: %d misses: %d\n",
        //     x, y,
        //     is_inside(x, y),
        //     count[1], count[0]
        // );
    }
    // printf("hits: %d misses: %d\n", count[1], count[0]);
    if (!count[0] && !count[1])
        printf("hit ratio: nan\n");
    else
        printf("hit ratio: %.3lf\n", (double)count[1] / (count[0] + count[1]));
}

int main(int argc, char** argv) {
    // printf("argc = %d\n", argc);
    // for (int i = 0; i < argc; i += 1)
    //     printf("argv[%d] = %s\n", i, argv[i]);

    FILE* file = 0;

    if (argc > 2) {
        printf("invalid arguments\n");
        return 2;
    }

    if (argc == 1) {
        file = stdin;
    }

    if (argc == 2) {
        file = fopen(argv[1], "rt");
        if (!file) {
            printf("no such file: %s\n", argv[1]);
            return 1;
        }
    }

    _main(file);
    return 0;
}
