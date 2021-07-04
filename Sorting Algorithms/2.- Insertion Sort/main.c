#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10];
    int n, i, j, temp;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for(i = 0; i<n; i++)
    {
        printf("Enter element number %d:\n", i);
        scanf("%d", &A[i]);
    }

    printf("\nBefore sorting Elements are: ");
    for(i = 0; i<n; i++)
    {
        printf("%d ", A[i]);
    }

    for(i = 1; i<n; i++)
    {
        temp = A[i];

        for(j = i; j > 0 && temp < A[j-1]; j--)
        {
            A[j] = A[j-1];
        }

        A[j] = temp;
    }

    printf("\nAfter sorting Elements are: ");
    for(i = 0; i<n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
