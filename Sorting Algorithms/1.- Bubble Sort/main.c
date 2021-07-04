#include <stdio.h>
#include <stdlib.h>


int main()
{
    int A[10], n;
    int i, j, temp;

    printf("Enter size of array: \n");
    scanf("%d", &n);

    for(i = 0; i<n; i++)
    {
        printf("Ente element number %d :", i);
        scanf("%d", &A[i]);
        printf("\n");
    }

    for(i = 1; i<n; i++)
    {
        for(j = 0; j<n-i; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }

    printf("Elements are: ");
    for(i = 0; i<n; i++)
    {
        printf("%d ", A[i]);
    }


    return 0;
}
