#include <stdio.h>

int main() {

    // Problem Inputs
    double x = 10.0;
    double y = 5.0;

    // Calculations
    double sum = x + y;
    double difference = x - y;
    double product = x * y;
    double quotient = x / y;

    // Print Statements
    printf("--------- First Value Set -----------\n");
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // serially hardcoded values from this point forward
    printf("\n--------- Second Value Set -----------\n");
    x = 40;
    y = 8;
    sum = x + y;
    difference = x - y;
    product = x * y;
    quotient = x / y;
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    printf("\n--------- Third Value Set -----------\n");
    x = 1;
    y = 4;
    sum = x + y;
    difference = x - y;
    product = x * y;
    quotient = x / y;
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    printf("\n--------- Fourth Value Set -----------\n");
    x = 15;
    y = 30;
    sum = x + y;
    difference = x - y;
    product = x * y;
    quotient = x / y;
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    return 0;
}