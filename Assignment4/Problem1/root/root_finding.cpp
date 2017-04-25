#include "root_finding.hpp"

using namespace std;

double f(double x) {
    return tan(x);
}
double fp(double x) {
    return 1/(cos(x)*cos(x));
}
double f2(double x) {
    return tanh(x);
}
double fp2(double x) {
    return 1/(cosh(x)*cosh(x));
}

int main() {
    cout << " Algorithms for root of tan(x)\n"
         << " ------------------------------------------------\n";
 
//    cout << " 1. Simple search\n"
//         << " Enter initial guess x_0, step dx, and desired accuracy: ";
//    double x0, dx, acc;
//    cin >> x0 >> dx >> acc;
//    double answer = root_simple(f, x0, dx, acc,1000,true);

    cout << " 1. Secant search\n"
         << " Enter bracketing guesses x_1, x_2, and desired accuracy: ";
    double x0, x1, acc;
    cin >> x0 >> x1 >> acc;
    cout << " Answer = " << root_secant(f, x0, x1, acc,1000,true) << endl;

    cout << "\n\n";
    cout << " 2. Tangent search\n"
         << " Enter bracketing guesses x_0 and desired accuracy: ";
    cin >> x0 >> acc;
    cout << " Answer = " << root_tangent(f, fp, x0, acc,20,true) << endl;

    cout << "\n\n";

    cout << " Algorithms for root of tanh(x)\n"
         << " ------------------------------------------------\n";

    cout << " 1. Secant search\n"
         << " Enter bracketing guesses x_1, x_2, and desired accuracy: ";
    cin >> x0 >> x1 >> acc;
    cout << " Answer = " << root_secant(f2, x0, x1, acc,1000,true) << endl;

    cout << "\n\n";
    cout << " 2. Tangent search\n"
         << " Enter bracketing guesses x_0 and desired accuracy: ";
    cin >> x0 >> acc;
    cout << " Answer = " << root_tangent(f2, fp2, x0, acc,20,true) << endl;






}
