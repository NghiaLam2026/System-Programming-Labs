#include <stdio.h>

void bubble_sort(int array[], int n, int *min, int *max);

int main() {
    int array[10];
    int min, max;
    int entered_number = 0;
    while (entered_number < 10) {
        printf("Please Enter Number %d: ", entered_number + 1);
        if (scanf("%d", &array[entered_number]) == 1) {
            entered_number++;
        }
    }

    bubble_sort(array, 10, &min, &max);

    printf("\n""[");
    for (int i = 0; i < 10; i++) {
        printf("%d", array[i]);
        if (i < 9) printf(", ");
    }
    printf("]\n");

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}

void bubble_sort(int array[], int n, int *min, int *max) {
    int *end = array + n; 
    int temp, *current, *next;

    for (current = array; current < end - 1; current++) {
        for (next = array; next < end - (current - array) - 1; next++) {
            if (*next > *(next + 1)) {
                temp = *next;
                *next = *(next + 1);
                *(next + 1) = temp;
            }
        }
    }

    *min = *array;
    *max = *(end - 1); 
}
