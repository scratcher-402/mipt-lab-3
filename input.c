#include "main.c"
void input_ship (int N, struct position *ship) {
    int d, m, c;
    struct coordinates lat;
    struct coordinates longitude;
    int flag = 1;
    for (int i = 0; i < N; i++) {
        flag = 1;
        while (flag == 1) {
            scanf ("%d%d%d", &d, &m, &c);
            flag = 0;
            if (c > 60 || c < 0 || m > 60 || m < 0 || d > 90 || d < 0) {
                flag = 1;
                printf ("Введите корректные значения\n");
            } else {
                lat.degree = d;
                lat.minute = m;
                lat.second = c;
            }
        }
        flag = 1;
        while (flag == 1) {
            scanf ("%d%d%d", &d, &m, &c);
            flag = 0;
            if (c > 60 || c < 0 || m > 60 || m < 0 || d > 180 || d < 0) {
                flag = 1;
                printf ("Введите корректные значения\n");
            } else {
                longitude.degree = d;
                longitude.minute = m;
                longitude.second = c;
            }
        }
        struct position p = {lat, longitude};
        ship[i] = p;
    }
    return;
}

struct fig input_triangle() {
    struct position apex[3];
    int d, m, c;
    struct coordinates lat;
    struct coordinates longitude;
    struct position p;
    int flag = 1;
    for (int i = 0; i < 3; i++) {
        flag = 1;
        while (flag == 1) {
            scanf ("%d%d%d", &d, &m, &c);
            flag = 0;
            if (c > 60 || c < 0 || m > 60 || m < 0 || d > 90 || d < 0) {
                flag = 1;
                printf ("Введите корректные значения\n");
            } else {
                lat.degree = d;
                lat.minute = m;
                lat.second = c;
            }
        }
        flag = 1;
        while (flag == 1) {
            scanf ("%d%d%d", &d, &m, &c);
            flag = 0;
            if (c > 60 || c < 0 || m > 60 || m < 0 || d > 180 || d < 0) {
                flag = 1;
                printf ("Введите корректные значения\n");
            } else {
                longitude.degree = d;
                longitude.minute = m;
                longitude.second = c;
            }
        }
        p.lat = lat;
        p.longitude = longitude;
        apex[i] = p;
    }
    struct fig triangle = {apex[0], apex[1], apex[2]};
    return triangle;
}

struct position input_port() {
    int d, m, c;
    struct coordinates lat;
    struct coordinates longitude;
    int flag = 1;
    while (flag == 1) {
        scanf ("%d%d%d", &d, &m, &c);
        flag = 0;
        if (c > 60 || c < 0 || m > 60 || m < 0 || d > 90 || d < 0) {
            flag = 1;
            printf ("Введите корректные значения\n");
        } else {
            lat.degree = d;
            lat.minute = m;
            lat.second = c;
        }
    }
    flag = 1;
    while (flag == 1) {
        scanf ("%d%d%d", &d, &m, &c);
        flag = 0;
        if (c > 60 || c < 0 || m > 60 || m < 0 || d > 180 || d < 0) {
            flag = 1;
            printf ("Введите корректные значения\n");
        } else {
            longitude.degree = d;
            longitude.minute = m;
            longitude.second = c;
        }
    }
    struct position p = {lat, longitude};
    return p;
}
