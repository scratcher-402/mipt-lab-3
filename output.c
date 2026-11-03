#include <stdio.h>

void danger_signal(size_t N, int *danger) {
    FILE *tty = fopen("/dev/tty", "r");
    if (tty == NULL) {
        tty = stdin;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Индекс судна\n");
    for (size_t i = 0; i < N; i++) {
        if (danger[i]) {
            printf("%lu %12s\n", i + 1, "YES");
            printf("\a");
        } else {
            printf("%lu %12s\n", i + 1, "NO");
        }
        while ((c = getc(tty)) != '\n' && c != EOF);
    }

    if (tty != stdin) {
        fclose(tty);
    }
}