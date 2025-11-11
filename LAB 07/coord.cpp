#include "coord.h"

void get_point(Point3D &pt){
    cout << "Enter ID: ";
    cin >> pt.id;
    cout << "Point ID: " << pt.id << endl << endl;

    cout << "Enter X coordinate: ";
    cin >> pt.x;
    cout << "X Coordinate: " << pt.x << endl << endl;

    cout << "Enter Y coordinate: ";
    cin >> pt.y;
    cout << "Y Coordinate: " << pt.y << endl << endl;

    cout << "Enter Z coordinate: ";
    cin >> pt.z;
    cout << "Z Coordinate: " << pt.z << endl << endl;

    cout << "Enter accuracy order (A/B/C): ";
    cin >> pt.order;
    cout << "Order: " << pt.order << endl << endl;
    
    return;
}

void print_point(const Point3D &pt) {
    cout << "Point ID:     "  << setw(10) << pt.id << endl;
    cout << "X Coordinate: "  << setw(10) << pt.x << endl;
    cout << "Y Coordinate: "  << setw(10) << pt.y << endl;
    cout << "Z Coordinate: "  << setw(10) << pt.z << endl;
    cout << "Order:        "  << setw(10) << pt.order << endl << endl;
}

double spatial_dist(const Point3D &pt1, const Point3D &pt2){
    return sqrt((pt1.x + pt2.x) * (pt1.x + pt2.x) +(pt1.y + pt2.y) * (pt1.y + pt2.y) + (pt1.z + pt2.z) * (pt1.z + pt2.z));
}

double plani_dist(const Point3D &pt1, const Point3D &pt2){
    return sqrt((pt1.x + pt2.x) * (pt1.x + pt2.x) +(pt1.y + pt2.y) * (pt1.y + pt2.y));
}

double height_diff(const Point3D &pt1, const Point3D &pt2){
    return pt2.z - pt1.z;
}

double azimuth(const Point3D &pt1, const Point3D &pt2){
    double rad = atan2((pt2.y - pt1.y), (pt2.x - pt1.x));
    return rad / M_PI * 180;
}