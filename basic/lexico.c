#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    
    while (a[i] != '\n' || b[i] != '\n') {
        if (a[i] > b[i])
            return 1;
        else if (a[i] < b[i])
            return 0;
        
        i++;
    }
    
    return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i = 0;
    
    while (a[i] != '\n' || b[i] != '\n') {
        if (a[i] < b[i])
            return 1;
        else if (a[i] > b[i])
            return 0;
        
        i++;
    }

    return 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {

    return 0;
}

int sort_by_length(const char* a, const char* b) {
    return 0;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    char temp[1024];
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int cmp = cmp_func(arr[i], arr[j]);
            
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }

    putchar('\n');
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%p\t%s\n", arr[i], arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%p\t%s\n", arr[i], arr[i]);
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%p\t%s\n", arr[i], arr[i]);
    printf("\n");

    // string_sort(arr, n, sort_by_number_of_distinct_characters);
    // for(int i = 0; i < n; i++)
    //     printf("%s\n", arr[i]); 
    // printf("\n");
}
