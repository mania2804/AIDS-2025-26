#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 0.001;

double poly(double x, double c[], int n) {
    double sum = 0.0;
    for (int i = 0; i <= n; i++) {
        sum += c[i] * pow(x, i);
    }
    return sum;
}

double bisection(double a, double b, double c[], int n) {
    double mid = (a + b) / 2.0;
    double fmid = poly(mid, c, n);

    if (fabs(fmid) <= EPS)
        return mid;

    double fa = poly(a, c, n);

    // Sprawdzenie zmiany znaku
    if ((fa < 0 && fmid > 0) || (fa > 0 && fmid < 0)) {
        return bisection(a, mid, c, n);
    } else {
        return bisection(mid, b, c, n);
    }
}

int main() {
    double a, b;
    int n;

    cout << "Podaj a i b: ";
    cin >> a >> b;

    cout << "Podaj stopien wielomianu n: ";
    cin >> n;

    // dynamiczna tablica współczynników
    double* c = new double[n + 1];

    cout << "Podaj " << n + 1 << " wspolczynnikow (od x^0 do x^" << n << "):\n";
    for (int i = 0; i <= n; i++) {
        cin >> c[i];
    }

    double fa = poly(a, c, n);
    double fb = poly(b, c, n);

    if ((fa > 0 && fb > 0) || (fa < 0 && fb < 0)) {
        cout << "Brak gwarancji miejsca zerowego w tym przedziale.\n";
        delete[] c;
        return 0;
    }

    double x = bisection(a, b, c, n);
    cout << "Znalezione miejsce zerowe: " << fixed;
    cout.precision(3);
    cout << x << endl;

    delete[] c;
    return 0;
}
