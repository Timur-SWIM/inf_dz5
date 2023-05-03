#include <stdio.h>

int main() {
    printf("%d\n", (10 / 2));
    for (int i = 0, j = 9; (i < 6 && j > 4); (i++, j--)){
        printf("%d->%d ", i , j);
    }
    return 0;
}
