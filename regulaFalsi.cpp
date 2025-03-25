#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function f(x) = 2x*cos(2x) - (x+1)^2
double f(double x) {
    return 2*x*cos(2*x) - pow(x + 1, 2);
}

// Regula Falsi (False Position) Method
void regulaFalsi(double x0, double x1, double tolerance) {
    cout << fixed << setprecision(5);
    cout << "----------------------------------------------------------------------------------\n";
    cout << "| i  |    x0       |    x1       |   f(x0)     |   f(x1)     |   New x   | f(New x) |\n";
    cout << "----------------------------------------------------------------------------------\n";

    int i = 1;
    double x_new, f_x0, f_x1, f_xnew;

    while (true) {
        f_x0 = f(x0);
        f_x1 = f(x1);

        // Compute new x using the Regula Falsi formula
        x_new = x1 - (f_x1 * (x1 - x0)) / (f_x1 - f_x0);
        f_xnew = f(x_new);

        cout << "| " << setw(2) << i << " | " << setw(10) << x0 << " | " << setw(10) << x1 
             << " | " << setw(10) << f_x0 << " | " << setw(10) << f_x1 
             << " | " << setw(10) << x_new << " | " << setw(10) << f_xnew << " |\n";

        // Stop if f(x_new) is exactly zero
        if (fabs(f_xnew) < tolerance) {
            cout << "----------------------------------------------------------------------------------\n";
            cout << "Root found: x = " << x_new << " where f(x) = 0 at iteration " << i << "\n";
            return;
        }

        // Update x0 or x1 based on the sign of f(x_new)
        if (f_x0 * f_xnew < 0) {
            x1 = x_new;
        } else {
            x0 = x_new;
        }

        i++;
    }
}

int main() {
    double x0 = -1.0, x1 = 0.0; // Initial guesses where f(x0) and f(x1) have opposite signs
    double tolerance = 1e-6;    // Precision threshold

    regulaFalsi(x0, x1, tolerance);

    return 0;
}
