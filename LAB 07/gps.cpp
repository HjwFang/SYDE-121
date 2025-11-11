#include "coord.h"

int main(){
    Point3D point1, point2;
    get_point(point1);
    get_point(point2);

    print_point(point1);
    print_point(point2);

    cout << "Spatial Distance: " << spatial_dist(point1, point2) << " units" << endl;
    cout << "Planimetric Distance: " << plani_dist(point1, point2) << " units" << endl;
    cout << "Height Difference: " << height_diff(point1, point2) << " units" << endl;
    cout << "Heading: " << azimuth(point1, point2) << " degrees" << endl;
    return 0;
}
