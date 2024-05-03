#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void reverseString(char *str);
void swap(char *left, char *right);

int main(){
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = 0;
    
    printf("Original String: %s\n", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    
    return 0;
}

void reverseString(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        swap(&str[i], &str[length - i - 1]);
    }
}

void swap(char *left, char *right) {
    char temp = *left;
    *left = *right;
    *right = temp;
}