#include <complex.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

struct Class {
    int *nums;
};

void test() {
    int num = 2048;
    char num_c;
    int new_num;

    // snprintf(num_c, 8, "%d\n", num);

    new_num = (int)num_c;

    printf("%d\n", num);
    printf("%c\n", (char)num);
    printf("%d\n", new_num);

}

void change_ptr(int *ptr, int num) {
    *ptr = num;
}

void ptr_test() {
    int *ptr = malloc(sizeof(int));
    *ptr = 5;

    int temp = *ptr;
    *ptr = 10;

    change_ptr(ptr, 15);

    printf("%d\n", *ptr);
    printf("%d\n", temp);

    free(ptr);
}

int pstr_len(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }

    return i + 1;
}

int dpstr_len(char **str) {
    int i=0;
    while (str[i] != NULL) {
        int j=0;
        while (str[i][j] != '\0') {
            j++;
        }

        printf("%s\t:\t%d\n", *(str + i), j);
        i++;
    }

    return i;
}

// void strtok_test() {
//     char str[] ="- This, a sample string.";
//     char * pch;
//     printf ("Splitting string \"%s\" into tokens:\n",str);
//     pch = strtok (str," ,.-\0");
//     while (pch != NULL)
//     {
//         printf ("%s\n",pch);
//         pch = strtok (NULL, " ,.-\0");
//     }
// }

void strtok_test() {
    char *str ="- This, a sample string.";
    char newstr[pstr_len(str)];
    char * pch;
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok (str," ,.-\0");
    while (pch != NULL)
    {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-\0");
    }
}


// char ** split_string(char *str,  char *tok) {
//     uint32_t max_len = 255;
//     char **found_str = malloc(max_len);
//
//     char *pch = strtok(str, tok);
//     uint32_t count = 0;
//     while (pch != NULL) {
//         count++;
//
//         if (count > max_len) {
//             found_str = realloc(found_str, max_len * 2);
//         } 
//
//         *(found_str + count) = pch;
//
//         pch = strtok(NULL, tok); 
//     }
//
//     return found_str;
// }

void arr_alloc (size_t x, size_t y, char (**aptr)[x][y])
{
  *aptr = malloc( sizeof(int[x][y]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}

void arr_fill (size_t x, size_t y, char array[x][y])
{
  for(size_t i=0; i<x; i++)
  {
    for(size_t j=0; j<y; j++)
    {
      array[i][j] = (int)j + 1;
    }
  }
}

void arr_print (size_t x, size_t y, char array[x][y])
{
  for(size_t i=0; i<x; i++)
  {
    for(size_t j=0; j<y; j++)
    {
      printf("%d ", array[i][j]);
    }
    printf("\n");
  }
}

bool is_delim(char ch, const char *tok) {
    int i = 0;

    while (tok[i] != '\0') {
        if (tok[i] == ch) {
            return true;
        }

        i++;
    }

    return false;
}

void split_string(char *str, const char *tok) {
    char (*ret_str)[16][64];
    ret_str = malloc( sizeof(int[16][64]) );

    int i = 0;
    int first_pos = 0, last_pos = 0;
    do {
        if (is_delim(str[last_pos], tok) || str[last_pos + 1] == '\0') {
            if (first_pos != last_pos) {
                memmove(ret_str[i], str + first_pos, last_pos);

                i++; 
            }

            last_pos++;
            first_pos = last_pos;
            continue;
        } 

        last_pos++;
    } while (str[last_pos] != '\0');

    for (int l = 0; l < i; l++) {
        printf("%s\n", *ret_str[l]);
    }
}

void read_from_file_test() {
    char *buffer = malloc(255);
    FILE *file = fopen("sample-data.txt", "r");
}

int main(void) {
    // ptr_test();
    // printf("%u\n", sizeof(short));

    // char *str = "Hello World";
    // printf("Length of '%s': %d\n", str, pstr_len(str));
    //
    // char *dstr[] = { "Hello", "World" };
    // printf("Length: %d\n", dpstr_len(dstr));

    // char *str[][] = malloc(sizeof(char[2][32]));
    // str[0] = "Hello";
    // str[1] = "World";
    //
    // for (int i = 0; i < 2; i++) {
    //     printf("%s\n", *(str + i));
    // }

    // strtok_test();
    // char **str = malloc(255);
    // printf("%d\n", pstr_len("Hell0 , Wordl"));
    // split_string("Hell0 , Wordl", ", ");
    //
    // int i = 0;l
    // while (*(str + i) != NULL) {
    //     printf("%s\n", *(str + i));
    // }
    // free(str);

    // int num  = 255 & (int)(pow(2, 4) - 1);
    // printf("%d\t|\t%x\n", num, num);

    int nums[10];

    for (int i = 0; i < 10; i++)
        nums[i] = i;

    struct Class cls = { nums };

    for (int i = 0; i < 10; i++)
        cls.nums[i] *= 10;

    for (int i = 0; i < 10; i++)
        printf("%d\n", nums[i]);

    return 0;
}
