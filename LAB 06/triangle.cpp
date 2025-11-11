#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void enter_sides(double&, double&, double&);

int check_sides(double, double, double);

double calculate_angle(double, double, double);

int main(){
    double a, b, c;
    enter_sides(a, b, c);

    if (check_sides(a, b, c) == 1){
        return 1;
    }

    cout << fixed << setprecision(2) << calculate_angle(a, b, c) << endl;
    return 0;
}

void enter_sides(double &a, double &b, double &c){
    cout << "Enter sides a, b, c:" << endl;
    cin >> a >> b >> c;
    return;
}

int check_sides(double a, double b, double c){
    if (a <= 0 || b <= 0 || c <= 0 || cin.fail()){
        return 1;
    } else if (a + b <= c || a + c <= b || b + c <= a){
        return 1;
    } else {
        return 0;
    }
}

double calculate_angle(double a, double b, double c){
    double rad_angle;
    double pi = 3.14159265358979323846;
    rad_angle = (acos((a * a + b * b - c * c)/(2.0 * a * b)));
    return (rad_angle / pi * 180.0);
}