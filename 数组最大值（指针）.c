/********Ѱ�������е����ֵ********/

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

void max_min(int *a, int n, int *max, int *min)   //���ص�ַ��������Ҫ��*Ϊ&
{
    int i;

    //i = a;

    *max = *a;
    *min = *max;

    for(i = 1; i < n; i++)
    {
        if (a[i] > *max)            //i[1]�൱��*(i+1)
            *max = a[i];
            //printf("%d\n",*max);       //ֻ����i��Ϊ��������ָ����������ж�


        else if (a[i] < *min)
            *min = a[i];
            //printf("%d\n",*min);


    }

}

/*******************�������***************
void max_min(int *a, int n, int *max, int *min)
{
    int i*;

    //i = a;

    *max = *a; / max = min = a ��ʱ�ķ���ֵ�Ǵ���ģ���һ����ַ
    *min = *max;

    for(i = a; i < a + n; i++)
    {
        if (i[1] > *max)          //i[1]�൱��*(i+1)
            *max = *i; / max = i
            //printf("%d\n",*max);       //ֻ����i��Ϊ��������ָ����������ж�


        else if (a[i] < *min)
            *min = *i;
            //printf("%d\n",*min);


    }

}

*******/
