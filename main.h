#pragma once

void input_ship(int N, position* ship);
fig input_triangle();
void input_triangle (fig* triangle);
position input_port();

void matrix_of_slopes(int N, position *ship, fig triangle, position port, float (*slopes)[4]);

void danger_identification (int N, float (*slopes)[4], int *danger);

void danger_signal (int N, int *danger);

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
