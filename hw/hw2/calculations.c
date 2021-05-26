#include <stdio.h>

int main(){

    // Problem Inputs
    double x = 10.0;
    double y = 5.0;

    // Calculations
    double sum = x + y;
    double difference = x - y;
    double product = x * y;
    double quotient = x/y;

    // Print Statements
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    return 0;
}