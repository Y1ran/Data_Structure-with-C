/**选择排序
test version 1::
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef N
#define N 10
#endif // N


inline int swap(int *s1, int *s2)   //交换函数
{
    int tmp;

    tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

inline int Select_Sort(int *arr, int len)
{

    register int i, j;

    for(i = 0; i != len ; i++)
    {

        for(j = i + 1;j != len; j++) //其实这里用while更好
        {
            if(arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
            }
            else
                continue;
    }
    }
}

int main( int argc, int *argv[])
{
    //test

    printf("please enter 10 numbers: \n");
    int i, arr[N];

    for(i = 0;i < N;i++)
    {

        scanf("%d", &arr[i]);

    }

    int len = sizeof(arr) / sizeof(arr[0]);

    Select_Sort(arr, len);

    printf("\n");
    printf("the ordered array is: \n");

    for(i = 0;i < N;i++)
    {
        printf("%4d", arr[i]);

    }

    return 0;
}
