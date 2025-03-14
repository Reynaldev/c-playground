#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, size_t len) {
    for (int i = len - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            if (*(arr + j) < *(arr + j - 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j - 1);
                *(arr + j - 1) = temp;
            }
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Not enough arguments!\n");
        return 0;
    }

    int len = argc - 1;
    int *arr = malloc(sizeof(int) * len);

    // Insert arguments to arr
    for (int i = 0; i < len; i++) {
        *(arr + i) = atoi(*(argv + i + 1));
    }

    // Print current
    printf("Unsorted: ");
    for (int i = 0; i < len; i++) {
        int c = *(arr + i);
        printf("%d ", c);
    }
    putchar('\n');

    sort(arr, len);

    // Print solved
    printf("Sorted: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", *(arr + i));
    }
    putchar('\n');

    free(arr);

    return 0;
}
