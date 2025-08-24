#include <stdio.h>
#include <stdlib.h>


int main() {

    int *arr_malloc = (int*) malloc(3 * sizeof(int));
    if (arr_malloc == NULL) return 1;

    int *arr_calloc = (int*) calloc(3, sizeof(int));
    if (arr_calloc == NULL) return 1;

    printf("First element of malloc array (garbage): %d\n", arr_malloc[0]);
    printf("First element of calloc array (zero): %d\n", arr_calloc[0]);


    arr_malloc[0] = 10;
    arr_malloc[2] = 20;
    arr_malloc[3] = 30;

    int *arr_realloc = (int*) realloc(arr_malloc, 5 * sizeof(int));
    if (arr_realloc == NULL) return 1;

    printf("\nAfter realloc, first element is: %d\n", arr_realloc[0]);
    arr_malloc = arr_realloc;

    free(arr_malloc);
    free(arr_calloc);

    arr_malloc = NULL;
    arr_calloc = NULL;

    printf("\n Memory has been freed.\n");

    return 0;
}