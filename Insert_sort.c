/**
  Insert排序数组
  version: 直接插入排序
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef N
#define N 100
#endif // N

int arr[N];

inline int Insert_Sort( int *arr)
{
    register int i, j, tmp;
    int k;
    //int len = sizeof(arr);

    for(i = 1; i < N/10; i++)
    {
        printf("\n");
        printf("The %dth times is: \n", i);

        tmp = arr[i];
        j = i - 1;

        while( tmp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = tmp;

        for(k = 0;k < N/10;k++)
        {
         printf("%2d |", arr[k]);
        }


    }
}

int Shell_Sort(int *arr)
{
    int i, j, k, tmp;
    int incre;

    for(incre = N/20; incre >= 1;incre /= 2)
    {
        for(i = incre; i < N/10; i++)
        {
            printf("\n");
            printf("The %dth times is: \n", i);

            tmp = arr[i];
           // j = i - 1;
            j = i - incre;
            while( j >= 0 && tmp < arr[j])
            {
                arr[j + incre] = arr[j];
                j -= incre;
            }
            arr[j + incre] = tmp;

            for(k = 0;k < N/10;k++)
            {
            printf("%2d |", arr[k]);
            }


        }
    }
}

int main( int argc, int *argv[])
{
    int i;


    printf("please enter 10 numbers: \n");

    for(i = 0;i < N/10;i++)
    {
        scanf("%d", &arr[i]);
    }

    Shell_Sort(arr);

    printf("\n");
    printf("the ordered array is: \n");

    for(i = 0;i < N/10;i++)
    {
        printf("%4d", arr[i]);

    }
}
