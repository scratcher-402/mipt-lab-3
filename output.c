#include <stdio.h>

<<<<<<< HEAD
void danger_signal(const size_t N, int *danger) {
=======
void danger_signal(size_t N, int *danger) {
>>>>>>> 64d8b2620e73a013a98811727cdc245250faa616
    FILE *tty = fopen("/dev/tty", "r");
    if (tty == NULL) {
        tty = stdin;
    }
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Индекс судна\n");
    for (size_t i = 0; i < N; i++) {
        if (danger[i]) {
            printf("%lu %12s", i + 1, "YES");
            printf("\a");
        } else {
            printf("%lu %12s", i + 1, "NO");
        }
        while ((c = getc(tty)) != '\n' && c != EOF);
    }

    if (tty != stdin) {
        fclose(tty);
    }
}