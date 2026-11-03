#include <stdio.h>

void danger_signal(size_t N, int *danger) {
    printf("Индекс судна\n");
    for (size_t i = 0; i < N; i++) {
        if (!danger[i]) {
            printf("%lu %-12s", i, "YES");
        } else {
            printf("%lu %-12s", i, "NO");
        }
        getc(stdin);
    }
}