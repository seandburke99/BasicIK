#ifndef POINT_H
#define POINT_H

typedef struct point{
    int x;
    int y;
} point;

point new_point(int x, int y);
double dir(const point *p);
double mag(const point *p);
void rotate_around(const point *o, point *p, double theta);

#endif