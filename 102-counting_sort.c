#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = array[0];
    size_t i;


    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int *sorted = malloc(size * sizeof(int));
    if (sorted == NULL) {
        free(count);
        return;
    }

    for (i = 0; i < size; i++) {
        sorted[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = sorted[i];

    printf("%d", count[0]);
    for (i = 1; i <= max; i++)
        printf(", %d", count[i]);
    printf("\n");

    free(count);
    free(sorted);
}
