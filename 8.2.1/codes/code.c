#include <stdio.h>
#include <math.h>

// Define the function to integrate
double f(double x) {
    return sqrt(9.0/4.0 - x*x) - (x*x) / 4.0;
}

// Function to calculate the area using the trapezoidal rule
double trapezoidal_rule(double a, double b, int n) {
    double dx = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));  // Add the first and last terms

    for (int i = 1; i < n; i++) {
        sum += f(a + i * dx);  // Add the intermediate terms
    }

    return sum * dx;  // Multiply by the width of each subinterval
}

int main() {
    double a = -sqrt(2);  // Lower limit
    double b = sqrt(2);   // Upper limit
    int n = 1000;         // Number of subintervals

    double area = trapezoidal_rule(a, b, n);

    // Open the file for writing
    FILE *fout = fopen("area_result.dat", "w");

    if (fout != NULL) {
        // Write the area to the .dat file
        fprintf(fout, "The area is approximately: %lf\n", area);
        fclose(fout);  // Close the file
        printf("The result has been written to area_result.dat\n");
    } else {
        printf("Error opening the file!\n");
    }

    return 0;
}

