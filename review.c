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

inline void insert_st(int high);
void swap( int *s1, int *s2);
void swap( int *s1, int *s2)
{
    int *tmp;

    *tmp = *s1;
    *s1 = *s2;
    *s2 = *tmp;
}

inline void insert_st(int high)
{
    //int i = low;
    register int i, tmp;// = high;
    register int j;
    int incre;

for(incre = N/20; incre >= 1; incre /= 2){
    for(i = incre; i < high; i += incre)
    {
        printf("\n");
        printf("The %dth times is: \n", i);

        j = i - incre;
        tmp = arr[i];
        while(tmp < arr[j] && j >= 0)
        {
            arr[j + incre] = arr[j];
            j -= incre;
        }

        arr[j + incre] = tmp;

        int k;
        for(k = 0;k < N/10;k++)
        {
         printf("%2d |", arr[k]);
        }

    }
}

}




int main( int argc, int *argv[])
{
    register int i;

    printf("please enter 10 numbers: \n");

    for(i = 0;i < N/10;i++)
    {
        scanf("%d", &arr[i]);
    }

    insert_st(N/10);

    printf("\n");
    printf("the ordered array is: \n");

    for(i = 0;i < N/10;i++)
    {
        printf("%4d", arr[i]);

    }
}
