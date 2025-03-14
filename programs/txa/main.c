#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/limits.h>

enum txa_mode { ENC, DEC };

void txa_show_help(void)
{
    printf(
        "How to use:\n"
        "\t./txa 'some words'\n"
        "\t./txa d filename.txa\n\n"
        "Options:\n"
        "\td\tDecode a file\n"
    );
}

size_t txa_word_len(const char *text)
{
    size_t i = 0;
    while (*(text + i) != '\0') { i++; }
    return i;
}

int txa_write(const char *text, const char *filename)
{
    FILE * pFile;
    pFile = fopen(filename, "wb");
    if (pFile == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    fwrite(text, 1, txa_word_len(text), pFile);

    fclose(pFile);

    return 0;
}

int main(int argc, char **argv)
{
    if (argc < 2 || argc > 3) 
    {
        txa_show_help();
        return 1;
    }

    enum txa_mode mode = ENC;

    char *in = malloc(1024);

    strcpy(in, *(argv + (argc - 1)));
    strcat(in, "\n");

    printf("Word:%s\nLength:%lu\n", in, txa_word_len(in));

    txa_write(in, "test_read.txa");

    free(in);

    return 0;
}