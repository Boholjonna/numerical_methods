#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function f(x) = 2x*cos(2x) - (x+1)^2
double f(double x) {
    return 2*x*cos(2*x) - pow(x + 1, 2);
}

// Derivative f'(x) = 2cos(2x) - 4x*sin(2x) - 2x - 2
double f_derivative(double x) {
    return 2*cos(2*x) - 4*x*sin(2*x) - 2*x - 2;
}

// Newton-Raphson Method
void newtonRaphson(double x0, double tolerance, int maxIterations) {
    cout << fixed << setprecision(5);
    cout << "------------------------------------------------------\n";
    cout << "| i  |    x        |    f(x)      |   f'(x)    | New x  |\n";
    cout << "------------------------------------------------------\n";

    int i = 1;
    double x = x0;
    double fx = f(x);
    
    while (fabs(fx) > tolerance && i <= maxIterations) {
        double dfx = f_derivative(x);

        if (dfx == 0) {  // Prevent division by zero
            cout << "Derivative is zero, Newton-Raphson method fails.\n";
            return;
        }

        double newX = x - fx / dfx;
        cout << "| " << setw(2) << i << " | " << setw(10) << x << " | " << setw(12) << fx << " | " 
             << setw(10) << dfx << " | " << setw(10) << newX << " |\n";

        // Update values
        x = newX;
        fx = f(x);
        i++;
    }

    // Display the final root
    cout << "------------------------------------------------------\n";
    cout << "Root found: x = " << x << " where f(x) = " << fx << "\n";
}

int main() {
    double initialGuess = -1.0; // Starting point for Newton-Raphson
    double tolerance = 1e-6;    // Precision threshold
    int maxIterations = 100;    // Prevent infinite loops

    newtonRaphson(initialGuess, tolerance, maxIterations);

    return 0;
}
