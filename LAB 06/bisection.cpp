#include <iostream>
#include <cmath> 
#include <iomanip>
#include <limits>
using namespace std;

const double PI = 3.14159265358979323846;
const int MAX_ITER = 256;

double f(double theta_deg, double rhs);

double bisection(double lo, double hi, double rhs, double tol);

int main(){
    double rhs, lo, hi, tol;
    cin >> rhs >> lo >> hi >> tol;

    if (cin.fail()){
        return 1;
    } else if (lo >= hi || lo < 0 || hi > 89){
        return 1;
    } else if (tol < 1e-15 || tol > 1e-6){
        return 1;
    }

    double f_lo = f(lo, rhs);
    double f_hi = f(hi, rhs);

    if (fabs(f_lo) < tol) {
        cout << fixed << setprecision(10) << lo << " deg" << endl;
        cout << scientific << setprecision(12) << f_lo << endl;
        return 0;
    } else if (fabs(f_hi) < tol) {
        cout << fixed << setprecision(10) << hi << " deg" << endl;
        cout << scientific << setprecision(12) << f_hi << endl;
        return 0;
    }

    if ((f_lo * f_hi) > 0){
        return 1;
    }
    
    double theta = bisection(lo, hi, rhs, tol);

    cout << fixed << setprecision(10) << theta << " deg" << endl;
    cout << scientific << setprecision(12) << f(theta, rhs) << endl;

    return 0;
}

double f(double theta_deg, double rhs){
    double theta_rad = theta_deg * PI / 180;
    return (tan(theta_rad) - sin(theta_rad) - rhs);
}

double bisection(double lo, double hi, double rhs, double tol){
    double mid;
    int iter = 0;
    for (int i = 0; i < MAX_ITER; i++) {
        mid = (lo + hi) / 2.0;
        double f_mid = f(mid, rhs);
        
        if (fabs(f_mid) < tol || (hi - lo) < 1e-12) {
            return mid;
        }
        
        double f_lo = f(lo, rhs);
        if (f_mid * f_lo < 0) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    
    return mid;
}