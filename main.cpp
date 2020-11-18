#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void main() {
    const double Pi = acos(-1.0);
    double xp, xk, x, dx, eps, a, S;
    int n;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "---------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "   |"
        << setw(10) << "acos(x)" << "  |"
        << setw(7) << "(Pi)/2.-(x+S)" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "---------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 1;
        a = pow(x, 3) / 6.;
        S = a + x;
        do {
            n++;
            a *= (pow(2 * n - 1, 2) * pow(x, 2)) / (2. * n * (2. * n + 1));
            S += a;
        } while (abs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << acos(x) << "  |"
            << setw(10) << setprecision(5) << Pi / 2 - S << "    |"
            << setw(5) << n << " |"s
            << endl;
        x += dx;
    }
    cout << "---------------------------------------------" << endl;
}