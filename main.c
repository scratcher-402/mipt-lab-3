#include "main.h"
#include <stdio.h>

int main()
{
    const size_t N;
    position ship[50];
    fig triangle;
    position port;

    double slopes[50][4]={};
    int danger[50]={};

    scanf("%zd", &N);

    //1
    input_ship(N, ship);
    triangle = input_triangle();
    port = input_port();

    //2
    matrix_of_slopes(N, ship, triangle, port, slopes);

    //3
    danger_identification(N, slopes, danger);

    //4
    danger_signal(N, danger);

    return 0;
}
