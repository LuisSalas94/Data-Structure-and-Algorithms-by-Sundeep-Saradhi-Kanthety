#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}


void display(int A[])
{
     for(int i = 0; i<10; i++)
    {
        printf("%d ", A[i]);
    }
}


int main()
{

    int A[] = {3,7,9,10,6,5,12,4,11,2};
    int n = 10;

    int i, j, min;

    for(i = 0; i<n; i++)
    {
        min = i;
        for(j = i+1; j<n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }

        swap(&A[i], &A[min]);
    }

    display(A);

    return 0;
}
