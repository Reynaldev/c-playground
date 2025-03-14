#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    clock_t start = clock();

    int len = 32;
    char *string = malloc(len);

    for (int i = 0; i < 4096 - 1; i++) {
        if (i > len) {
            string = realloc(string, len + 1);
            len++;
        }
        
        string[i] = 'A';
    }

    string = realloc(string, len + 1);
    string[len + 1] = '\n';
    
    // string[len] = '\n';

    clock_t end = clock();

    float f = (float)(end - start);

    printf("Text:\t%s\n", string);
    printf("Time:\t%.12fs\n", (float)(f / CLOCKS_PER_SEC));

    return 0;
}
