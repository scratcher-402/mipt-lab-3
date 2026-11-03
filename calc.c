#include <stdio.h>
#include "main.h"

void matrix_of_slopes(size_t N, position *ship, fig triangle, position port, double (*slopes)[4]) 
{
    double port_longitude = (double)port.longitude.degree + (double)(port.longitude.minute) / 60 + (double)(port.longitude.second) / 3600;
    double port_lat = (double)port.lat.degree + (double)(port.lat.minute) / 60 + (double)(port.lat.second) / 3600;
    double apex1_longitude = (double)triangle.apex1.longitude.degree + (double)(triangle.apex1.longitude.minute) / 60 + (double)(triangle.apex1.longitude.second) / 3600;
    double apex1_lat = (double)triangle.apex1.lat.degree + (double)(triangle.apex1.lat.minute) / 60 + (double)(triangle.apex1.lat.second) / 3600;
    double apex2_longitude = (double)triangle.apex2.longitude.degree + (double)(triangle.apex2.longitude.minute) / 60 + (double)(triangle.apex2.longitude.second) / 3600;
    double apex2_lat = (double)triangle.apex2.lat.degree + (double)(triangle.apex2.lat.minute) / 60 + (double)(triangle.apex2.lat.second) / 3600;
    double apex3_longitude = (double)triangle.apex3.longitude.degree + (double)(triangle.apex3.longitude.minute) / 60 + (double)(triangle.apex3.longitude.second) / 3600;
    double apex3_lat = (double)triangle.apex3.lat.degree + (double)(triangle.apex3.lat.minute) / 60 + (double)(triangle.apex3.lat.second) / 3600;

    for (size_t i = 0; i < N; i++) {
        double ship_longitude = (double)ship[i].longitude.degree + (double)(ship[i].longitude.minute) / 60 + (double)(ship[i].longitude.second) / 3600;
        double ship_lat = (double)ship[i].lat.degree + (double)(ship[i].lat.minute) / 60 + (double)(ship[i].lat.second) / 3600;
        double port_lambda = (double)(port_lat - ship_lat) / (double)(port_longitude - ship_longitude);
        double apex1_lambda = (double)(apex1_lat - ship_lat) / (double)(apex1_longitude - ship_longitude);
        double apex2_lambda = (double)(apex2_lat - ship_lat) / (double)(apex2_longitude - ship_longitude);
        double apex3_lambda = (double)(apex3_lat - ship_lat) / (double)(apex3_longitude - ship_longitude);

        slopes[i][0] = apex1_lambda;
        slopes[i][1] = apex2_lambda;
        slopes[i][2] = apex3_lambda;
        slopes[i][3] = port_lambda;
    }
}
