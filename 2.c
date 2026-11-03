#include <stdio.h>

typedef struct coordinates
{   
    int degree;
    int minute;
    int second;
} coordinates;

typedef struct position
{ 
    struct coordinates lat;
    struct coordinates longitude;
} position;

typedef struct fig
{
    struct position apex1;
    struct position apex2;
    struct position apex3;
} fig;

void matrix_of_slopes (size_t N, position *ship, fig triangle, position port, double (*slopes)[4]) {
    double port_longitude = port.longitude.degree + (port.longitude.minute) / 60 + (port.longitude.second) / 3600;
    double port_lat = port.lat.degree + (port.lat.minute) / 60 + (port.lat.second) / 3600;
    double apex1_longitude = triangle.apex1.longitude.degree + (triangle.apex1.longitude.minute) / 60 + (triangle.apex1.longitude.second) / 3600;
    double apex1_lat = triangle.apex1.lat.degree + (triangle.apex1.lat.minute) / 60 + (triangle.apex1.lat.second) / 3600;
    double apex2_longitude = triangle.apex2.longitude.degree + (triangle.apex2.longitude.minute) / 60 + (triangle.apex2.longitude.second) / 3600;
    double apex2_lat = triangle.apex2.lat.degree + (triangle.apex2.lat.minute) / 60 + (triangle.apex2.lat.second) / 3600;
    double apex3_longitude = triangle.apex3.longitude.degree + (triangle.apex3.longitude.minute) / 60 + (triangle.apex3.longitude.second) / 3600;
    double apex3_lat = triangle.apex3.lat.degree + (triangle.apex3.lat.minute) / 60 + (triangle.apex3.lat.second) / 3600;

    for (size_t i = 0; i < N; i++) {
        double ship_longitude = ship[i].longitude.degree + (ship[i].longitude.minute) / 60 + (ship[i].longitude.second) / 3600;
        double ship_lat = ship[i].lat.degree + (ship[i].lat.minute) / 60 + (ship[i].lat.second) / 3600;
        double port_lambda = (port_lat - ship_lat) / (port_longitude - ship_longitude);
        double apex1_lambda = (apex1_lat - ship_lat) / (apex1_longitude - ship_longitude);
        double apex2_lambda = (apex2_lat - ship_lat) / (apex2_longitude - ship_longitude);
        double apex3_lambda = (apex3_lat - ship_lat) / (apex3_longitude - ship_longitude);

        slopes[i][0] = apex1_lambda;
        slopes[i][1] = apex2_lambda;
        slopes[i][2] = apex3_lambda;
        slopes[i][3] = port_lambda;
    }
}