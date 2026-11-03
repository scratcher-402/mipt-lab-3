#include "main.h"
#include <stdio.h>

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
    
    position p = {lat, longitude};
    return p;
}
