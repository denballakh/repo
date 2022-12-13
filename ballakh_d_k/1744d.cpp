#include <stdio.h>

int count_zeros(int n) {
    int zeros = 0;
    while (!(n & 1)) {
        n >>= 1;
        zeros += 1;
    }
    return zeros;
}

int get_nearest_power_2(int n) {
    int power = 0;
    while (1 << power < n)
        power += 1;
    return power;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int _ = 0; _ < t; _ += 1) {
        int n; // length of array
        int cnt_2 = 0; // number of 2's in product

        scanf("%d", &n);
        for (int i = 0; i < n; i += 1) {
            int x;
            scanf("%d", &x);
            cnt_2 += count_zeros(x);
        }

        int op_cnt = 0; // performed operations
        int stop = cnt_2 >= n;
        for (
            int cur_power = get_nearest_power_2(n);
            !stop && cur_power;
            cur_power -= 1
        ) {
            for (
                int multiple_of_2 = 1 << cur_power;
                !stop && multiple_of_2 <= n;
                multiple_of_2 += 2 << cur_power
            ) {
                op_cnt += 1;
                cnt_2 += cur_power;
                stop = cnt_2 >= n;
            }
        }

        if (cnt_2 < n)
            printf("-1\n");
        else
            printf("%d\n", op_cnt);

    }
}
