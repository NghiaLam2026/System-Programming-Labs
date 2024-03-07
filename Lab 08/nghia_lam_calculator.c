#include <stdio.h>
#include <math.h>
#include <string.h>

double addition(double left, double right) {
    return left + right;
}

double subtraction(double left, double right) {
    return left - right;
}

double multiplication(double left, double right) {
    return left * right;
}

double division(double left, double right) {
    return left / right;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double floorDivision(double left, double right) {
    return floor(left / right);
}

int main() {
    double first, second, result;
    char operation[3]; // Array to hold the operation string, including null terminator

    printf("Please enter the first number: ");
    scanf("%lf", &first);
    printf("Please enter the second number: ");
    scanf("%lf", &second);

    printf("Do you want to +, -, *, /, **, or //?: ");
    scanf("%s", operation);

    if (strcmp(operation, "+") == 0) {
        result = addition(first, second);
        printf("%.2f + %.2f = %.2f\n", first, second, result);

    } else if (strcmp(operation, "-") == 0) {
        result = subtraction(first, second);
        printf("%.2f - %.2f = %.2f\n", first, second, result);

    } else if (strcmp(operation, "*") == 0) {
        result = multiplication(first, second);
        printf("%.2f * %.2f = %.2f\n", first, second, result);

    } else if (strcmp(operation, "/") == 0) {
        result = division(first, second);
        printf("%.2f / %.2f = %.2f\n", first, second, result);

    } else if (strcmp(operation, "**") == 0) {
        result = power(first, second);
        printf("%.2f ** %.2f = %.2f\n", first, second, result);

    } else if (strcmp(operation, "//") == 0) {
        result = floorDivision(first, second);
        printf("%.2f // %.2f = %.2f\n", first, second, result);

    } else {
        printf("Error: Invalid Operator (%s)\n",operation);
        return 1;
    }


    return 0;
}
