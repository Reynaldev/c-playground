#include <stdio.h>
#include <stdlib.h>

int mul_by_two(int n) {
    return n * 2;
}

int mul_by_three(int n) {
    return n * 3;
}

void print_something(int (*f)(int)) {
    printf("Result %d\n", f(5));
}

int main(void) {
    print_something(mul_by_two);
    print_something(mul_by_three);
}
