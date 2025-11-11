#ifndef coord_h
#define coord_h

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point3D{
    int id;
    double x;
    double y;
    double z;
    char order;
};

void get_point(Point3D &pt);
void print_point(const Point3D &pt);
double spatial_dist(const Point3D &pt1, const Point3D &pt2);
double plani_dist(const Point3D &pt1, const Point3D &pt2);
double height_diff(const Point3D &pt1, const Point3D &pt2);
double azimuth(const Point3D &pt1, const Point3D &pt2);

#endif