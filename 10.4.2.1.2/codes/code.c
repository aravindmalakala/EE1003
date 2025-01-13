#include <stdio.h>
#include <math.h>

// Function to calculate the value of f(x) = 2x^2 + x - 6
double f(double x) {
    return 2 * x * x + x - 6;
}

// Derivative of f(x): f'(x) = 4x + 1
double f_prime(double x) {
    return 4 * x + 1;
}

// Newton's method to find the root
double newtons_method(double x0, double target) {
    double x = x0, xprev;
    int i = 0;
    
    do {
        xprev = x;
        x = x - f(x) / f_prime(x);  // Newton's method formula
        i++;
        // Print iteration, current x value, and difference from previous value
        printf("%d\t\t %.10lf\t %.10lf\n", i, x, fabs(x - xprev));
    } while (fabs(x - target) >= 1e-6 && i < 1000);  // Stop if close to target or max iterations reached
    
    return x;
}

int main(void) {
    // Initial guesses for the roots (close to the expected roots)
    double guess1 = 1.0;  // Initial guess for root 1
    double guess2 = -3.0; // Initial guess for root 2
    
    // Target roots (approximate)
    double target1 = 1.5;
    double target2 = -2.0;

    printf("Finding root near x = %.2f:\n", target1);
    printf("Iteration\t x_n\t\t Difference\n");
    double root1 = newtons_method(guess1, target1);
    printf("Converged to root1 = %.10lf (close to %.2f)\n\n", root1, target1);
    
    printf("Finding root near x = %.2f:\n", target2);
    printf("Iteration\t x_n\t\t Difference\n");
    double root2 = newtons_method(guess2, target2);
    printf("Converged to root2 = %.10lf (close to %.2f)\n", root2, target2);

    return 0;
}

