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
    printf("--------- First Value Set -----------\n");
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // update x,y to (40, 8) ... print it again!
    double x = 40;
    double y = 8;
    printf("\n--------- Second Value Set -----------\n");
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // update x,y to (1, 4) ... print it again!
    double x = 1;
    double y = 4;
    printf("\n--------- Third Value Set -----------\n");
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    // update x,y to (15, 30) ... print it again!
    double x = 15;
    double y = 30;
    printf("\n--------- Fourth Value Set -----------\n");
    printf("Two Values:L %f and %f\n", x, y);
    printf("Sum: %f\n", sum);
    printf("Difference: %f\n", difference);
    printf("Product: %f\n", product);
    printf("Quotient: %f\n", quotient);

    return 0;
}