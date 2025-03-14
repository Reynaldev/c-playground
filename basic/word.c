#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *text = malloc(1024);

    char texts[] = 
        "Hello World, Lorem ipsum dolor sit amet lorem ipsum"
        "KLAWn akldwkwa kwandln akwdnl kand ka l nd a a ks ll oeo ";

    strcpy(text, texts);

    int word = 0;
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == ' ')
            word++;

        i++;
    }

    printf("Words: %d\nLength: %d\n", word + 1, i);

    return 0;
}
