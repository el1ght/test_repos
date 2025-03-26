#ifndef SORT
#define SORT
#include "stringProcessor.h"
void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}
void quick_sort(char** arr, size_t length)
{
    size_t piv = 0;
    if (length <= 1)
    {
        return;
    }
    for (size_t i = 0; i < length; i++)
    {
        if (strcmp(arr[i], arr[length - 1ull]) < 0)
        {
            swap(arr + i, arr + piv++);
        }
    }
    //move pivot to "middle"
    swap(arr + piv, arr + length - 1);
    quick_sort(arr, piv++);
    quick_sort(arr + piv, length - piv);
}
#endif // !SORT