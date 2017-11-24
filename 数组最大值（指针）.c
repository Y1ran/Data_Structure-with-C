/********寻找数组中的最大值********/

#include <stdio.h>
#include <stdlib.h>

#define N 5

void max_min(int *a, int n, int *max, int *min);

int main(void)
{
    int *p, b[N], i, big, small;

    //p = b;
    //&big = &small = i;
    printf("enter the %d numbers \n", N);
    for (p = b; p < b + N; p++)
    {
        scanf("%d",p);
    }

    max_min(b, N, &big, &small);

    printf("largest number is : %d\n", big);
    printf("smallest number is : %d\n", small);

    return 0;

}

void max_min(int *a, int n, int *max, int *min)   //传回地址的声明需要改*为&
{
    int i;

    //i = a;

    *max = *a;
    *min = *max;

    for(i = 1; i < n; i++)
    {
        if (a[i] > *max)            //i[1]相当于*(i+1)
            *max = a[i];
            //printf("%d\n",*max);       //只能用i作为常数而非指针进行自增判断


        else if (a[i] < *min)
            *min = a[i];
            //printf("%d\n",*min);


    }

}

/*******************错误代码***************
void max_min(int *a, int n, int *max, int *min)
{
    int i*;

    //i = a;

    *max = *a; / max = min = a 此时的返回值是错误的，是一串地址
    *min = *max;

    for(i = a; i < a + n; i++)
    {
        if (i[1] > *max)          //i[1]相当于*(i+1)
            *max = *i; / max = i
            //printf("%d\n",*max);       //只能用i作为常数而非指针进行自增判断


        else if (a[i] < *min)
            *min = *i;
            //printf("%d\n",*min);


    }

}

*******/
