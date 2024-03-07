#include <stdio.h>
#include <time.h>

#define FILENAME "buffered.txt"
#define ITERATIONS 1000000
#define STRING_TO_WRITE "This is a test string.\n"
#define STR_LENGTH 13

int main() {
    FILE *file_pointer;
    time_t start, end;
    int result;

    file_pointer = fopen(FILENAME, "w");

    time(&start);
    for (int i = 1; i <= ITERATIONS; i++) {
        result = fprintf(file_pointer, "%s", STRING_TO_WRITE);
        printf("%d: %d characters written to %s\n", i, STR_LENGTH, FILENAME);
    }
    time(&end);

    fclose(file_pointer);

    printf("Buffered I/O Time Elapsed: %ld seconds\n", end - start);

    return 0;
}
