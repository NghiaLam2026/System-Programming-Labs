#include <stdio.h>
#include <ctype.h> 

char most_freq_char_in_file(const char *filename, int *max_freq) {
    FILE *file = fopen(filename, "r");
    int count[256] = {0};
    int c; 

    while ((c = fgetc(file)) != EOF) {
        c = tolower(c);
        if (isalpha(c)) {
            count[c]++; 
        }
    }

    fclose(file);

    int max_count = 0;
    char max_char = '\0';
    for (int i = 'a'; i <= 'z'; i++) {
        if (count[i] > max_count) {
            max_count = count[i];
            max_char = i;
        }
    }
    *max_freq = max_count; 
    return max_char;
}

int main() {
    char filename[] = "sample.txt";
    int max_freq = 0;
    char mostFrequent = most_freq_char_in_file(filename, &max_freq);
    printf("Opening sample.txt\n");
    printf("The most frequent character is '%c'. It appeared %d times.\n", mostFrequent, max_freq);
    
    return 0;
}
