#include "main.h"
#include <stdio.h>

int check(size_t x, size_t n_max) {
    if (x <= n_max) {
        return 1;
    } else {
        return 0;
    }
}

int bad_lat(size_t d, size_t m, size_t c) {
    if (!(check(c, 60) && check(m, 60) && check(d, 90))) {
        return 1;
    } else {
        return 0;
    }
}

int bad_long(size_t d, size_t m, size_t c) {
    if (!(check(c, 60) && check(m, 60) && check(d, 180))) {
        return 1;
    } else {
        return 0;
    }
}

void input_ship(size_t N, position *ship)
{
    int d, m, c;
    coordinates lat;
    coordinates longitude;

    int flag = 1;
    for (size_t i = 0; i < N; i++) {
        flag = 1;
        
        while (flag == 1) {
            scanf ("%d%d%d", &d, &m, &c);
            flag = 0;
            if (bad_lat(d, m, c)) {
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
            if (bad_long(d, m, c)) {
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

fig input_triangle()
{
    position apex[3];
    int d, m, c;
    coordinates lat;
    coordinates longitude;
    position p;

    int flag = 1;
    for (size_t i = 0; i < 3; i++) {
        flag = 1;
        while (flag == 1) {
            scanf ("%d%d%d", &d, &m, &c);
            flag = 0;
            if (bad_lat(d, m, c)) {
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
            if (bad_long(d, m, c)) {
                flag = 1;
                printf("Введите корректные значения\n");
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
    fig triangle = {apex[0], apex[1], apex[2]};
    return triangle;
}

position input_port()
{
    int d, m, c;
    coordinates lat;
    coordinates longitude;
    int flag = 1;
    while (flag == 1) {
        scanf ("%d%d%d", &d, &m, &c);
        flag = 0;
        if (bad_lat(d, m, c)) {
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
        if (bad_long(d, m, c)) {
            flag = 1;
            printf ("Введите корректные значения\n");
        } else {
            longitude.degree = d;
            longitude.minute = m;
            longitude.second = c;
        }
    }
    
    position p = {lat, longitude};
    return p;
}
