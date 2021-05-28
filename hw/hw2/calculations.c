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
    printf("--------- First Value Set -----------")
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // update x,y to (40, 8) ... print it again!
    x = 40;
    y = 8;
    printf("\n--------- Second Value Set -----------")
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // update x,y to (1, 4) ... print it again!
    x = 1;
    y = 4;
    printf("\n--------- Third Value Set -----------")
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // update x,y to (15, 30) ... print it again!
    x = 15;
    y = 30;
    printf("\n--------- Fourth Value Set -----------")
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    return 0;
}