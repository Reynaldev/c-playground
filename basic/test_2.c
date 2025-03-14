#include <stdint.h>
#include <stdio.h>

int main(void) {
    for (uint8_t i = 0; i < 100; i++) {
        uint8_t n = 10;

        printf("%p\n", &n);
    }

    return 0;
}
