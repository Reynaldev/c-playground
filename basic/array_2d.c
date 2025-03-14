#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void arr_alloc (size_t x, size_t y, int(**aptr)[x][y])
{
  *aptr = malloc( sizeof(int[x][y]) ); // allocate a true 2D array
  assert(*aptr != NULL);
}

void arr_fill (size_t x, size_t y, int array[x][y])
{
  for(size_t i=0; i<x; i++)
  {
    for(size_t j=0; j<y; j++)
    {
      array[i][j] = (int)j + 1;
    }
  }
}

void arr_print (size_t x, size_t y, int array[x][y])
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

int main (void)
{
  size_t x = 2;
  size_t y = 3;
  int (*aptr)[x][y];

  arr_alloc(x, y, &aptr);
  arr_fill(x, y, *aptr);
  arr_print(x, y, *aptr);
  free(aptr); // free the whole 2D array

  return 0;
}
