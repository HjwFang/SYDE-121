#include "coord.h"

void get_point(Point3D &pt){
    cout << "Enter ID: ";
    cin >> pt.id;
    cout << endl << "Point ID: " << pt.id << endl;

    cout << "Enter X coordinate: ";
    cin >> pt.x;
    cout << endl << "X Coordinate: " << pt.x << endl;

    cout << "Enter Y coordinate: ";
    cin >> pt.y;
    cout << endl << "Y Coordinate: " << pt.y << endl;

    cout << "Enter Z coordinate: ";
    cin >> pt.z;
    cout << endl << "Z Coordinate: " << pt.z << endl;

    cout << "Enter accuracy order (A/B/C): ";
    cin >> pt.order;
    cout << endl << "Order: " << pt.order << endl;
    
    return;
}

void print_point(const Point3D &pt) {
    cout << "Point ID: "      << setw(10) << pt.id << endl;
    cout << "X Coordinate: "  << setw(10) << pt.x << endl;
    cout << "Y Coordinate: "  << setw(10) << pt.y << endl;
    cout << "Z Coordinate: "  << setw(10) << pt.z << endl;
    cout << "Order: "         << setw(10) << pt.order << endl;
}
