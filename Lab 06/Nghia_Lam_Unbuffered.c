#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define FILENAME "unbuffered.txt"
#define ITERATIONS 1000000
#define STRING_TO_WRITE "This is a test string.\n"

int main() {
    int fd;
    time_t start, end;
    size_t str_length = sizeof(STRING_TO_WRITE) - 1;

    fd = open(FILENAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    time(&start);
    for (int i = 0; i < ITERATIONS; i++) {
        printf("%d: Called write(%d, str_to_write, %d) which returned that %zd bytes were written.\n", i, fd, str_length, write);
    }
    time(&end);

    close(fd);

    printf("Unbuffered I/O Time Elapsed: %ld seconds\n", end - start);

    return EXIT_SUCCESS;
}
