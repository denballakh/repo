#include<stdio.h>
#include<math.h>
#include<assert.h>

bool unique(char c1, char c2, char c3) {
    if (c1 == '.') return false;
    if (c2 == '.') return false;
    if (c3 == '.') return false;
    if (c1 == c2) return false;
    if (c2 == c3) return false;
    if (c3 == c1) return false;
    return true;
}

void _main() {
    char str[1 << 14] = {0};
    scanf("%s", str);
    // printf("string: %s\n", str);
    if (!str[0] || !str[1] || !str[2]) {
        printf("NO\n");
        return;
    }
    int index = 2;
    for (
        char c1 = str[0], c2 = str[1], c3 = str[2];
        str[index];
        index += 1, c1 = c2, c2 = c3, c3 = str[index]
    ) {
        // printf("%c %c %c %d\n", c1,c2,c3,index);
        if (unique(c1, c2, c3)) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    _main();
}
