#include <stdlib.h>
#include <stdio.h>

typedef int my_int;

enum DataType {
    CHAR    = 1, 
    INT     = 1 << 1,
};

void array_fill(void **arr, void *e, enum DataType type, int x, int y) {
    if (type == CHAR) {
        char **arr = (char **) arr;
        char e = (char) e;
    } else {
        int **arr = (int **) arr;
        int e = (int) e;
    }

    // for (int i = 0; i < y; i++) {
    //     for (int j = 0; j < x; j++) {
    //         arr[i][j] = e;
    //     }
    // }
}

int main (void)
{
    int (*arr)[16] = malloc(sizeof(int[16][16]));

    // for (int i = 0; i < 16; i++) {
    //     for (int j = 0; j < 16; j++) {
    //         arr[i][j] = j;
    //     }
    // }

    array_fill((void **) arr, (void *) 2, CHAR, 16, 16);
    
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
           printf("%d ", arr[i][j]); 
        }

        putchar('\n');
    }

    return 0;
}
