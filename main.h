#pragma once
#include <stdlib.h>

typedef struct coordinates
{
    int degree;
    int minute;
    int second;
} coordinates;

typedef struct position
{ 
    coordinates lat;
    coordinates longitude;
} position;

typedef struct fig
{ 
    position apex1;
    position apex2;
    position apex3;
} fig;

void input_ship(const size_t N, position* ship);
fig input_triangle();
position input_port();

void matrix_of_slopes(const size_t N, position *ship, fig triangle, position port, double (*slopes)[4]);

void danger_identification(const size_t N, double (*slopes)[4], int *danger);

void danger_signal(const size_t N, int *danger);
