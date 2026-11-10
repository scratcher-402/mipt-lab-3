#include"main.h"

void danger_identification (const size_t N, double (*slopes)[4], int *danger) {
    for (size_t i = 0; i < N; i++) {
        danger[i] = 0;

        for (size_t l = 0; l < 3 && !danger[i]; l++) {
            for (size_t m = l + 1; m < 3; m++) {
                danger[i] |= (slopes[i][l] <= slopes[i][3] && slopes[i][3] <= slopes[i][m]) || (slopes[i][m] <= slopes[i][3] && slopes[i][3] <= slopes[i][l]);
            }
        }
    }
}
