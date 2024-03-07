#include <stdio.h>

void bubble_sort(int array[], int n, int *min, int *max);

int main(){
    int array[10];
    int min, max;
    int entered_number = 0;
    while(entered_number < 10){
        printf("Please Enter Number %d: ", entered_number + 1);
        if(scanf("%d", &array[entered_number]) == 1){
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

void bubble_sort(int array[], int n, int *min, int *max){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (array[j] > array[j + 1]){
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    *min = array[0];
    *max = array[n - 1];
}