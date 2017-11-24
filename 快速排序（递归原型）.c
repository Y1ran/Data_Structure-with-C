/***********���������㷨
���õݹ麯��|�汾1*********/

#include <stdio.h>
#include <stdlib.h>
#define N 10

void quick_sort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void)
{
    int a[N], i;


    printf("Please enter %d number of sorting: ", N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, N - 1);

    printf("In sorted order: ");
    for(i = 0; i < N; i++)
    {
        printf("%d \n", a[i]);

    }

    return 0;
}

void quick_sort(int a[], int low, int high)
{
    int middle;

    if(low >= high) return;
    middle = split(a, low, high);
    quick_sort(a, 0, middle - 1);
    quick_sort(a, middle + 1, N - 1);

}

int split(int a[], int low, int high)
{
    int value = a[low];

    for(;;)
    {
        while (low < high && value <= a[high])
            high--;
        if (low >= high) {
                break;}
        a[low++] = a[high];
        //low++;

        while (low < high && value >= a[low])
            low++;
        if (low >= high) break;
        a[high--] = a[low];
        //high--;
    }

    a[high] = value;
    return high;
}


/*******���ڷָ��ͬд�����������ƣ������ǵݹ��㷨
int split(int a[], int low, int high)
{
    int value = a[low]; //�������ʱ��ȡ�ױ꣬�����ľͲ���

    for(;;)
    {
        while (low < high && value <= a[high])
            high--;
        if (low >= high) {
                break;}
        a[low++] = a[high];
        //low++;

        while (low < high && value >= a[low])
            low++;
        if (low >= high) break;
        a[high--] = a[low];void quick_sort(int a[], int low, int high)
{
    int middle;

    if(low < high) return;
    middle = split(a, low, high);
    quick_sort(a, low, middle - 1);
    quick_sort(a, middle + 1, high);

}******************************/


