void danger_identification (int N, float (*slopes)[4], int *danger) {
    for (int i = 0; i < N; i++) {
        int k = 0;

        for (int l = 0; l < 3; l++) {
            if (k == 1) {
                break;
            }

            for (int m = l + 1; m < 3; m++) {
                if (slopes[i][l] <= slopes[i][3] && slopes[i][3] <= slopes[i][m]) {
                    k = 1;
                }
            }
        }

        if (k==1) {
            danger[i] = 1;
        } else {
            danger[i] = 0;
        }
    }
}
