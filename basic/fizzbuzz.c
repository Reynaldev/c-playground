#include <stdint.h>
#include <stdio.h>

int main(void) {
    for (uint8_t i = 1; i <= 100; i++) {
        if (i % 3 == 0) printf("Fizz");
        if (i % 5 == 0) printf("Buzz");

        putchar('\n');
    }

    return 0;
}
