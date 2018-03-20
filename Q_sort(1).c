/**quick_sort()
***Version 2: Basic Q_sort without swap
**/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef N
#define N 100
#endif // N

void swap(int *s1, int *s2);
int Q_sort(int *arr, int low,  int high);
int Insert_Sort(int *arr, int low, int high);
int Mid_pivot(int *arr, int low, int high);

int arr[N]; //global variant

void swap(int *s1, int *s2)
{
    int *tmp;

    *tmp = *s1;
    *s1 = *s2;
    *s2 = *tmp;

    //return;
}
inline int Insert_Sort(int *arr, int low, int high)
{
    register int i, j;
    int tmp;
    //int len = sizeof(arr);

    for(i = low; i < high; i++)
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

        int k;
        for(k = 0;k < N/10;k++)
        {
         printf("%2d |", arr[k]);
        }


    }
}

int Mid_pivot(int *arr, int low ,int high)
{
    int mid =low + (high - low) / 2;

    if( arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if( arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);
    if( arr[low] < arr[mid])
        swap(&arr[low], &arr[mid]);

    //return arr[low];
}

int Q_sort(int *arr, int low, int high)
{

    int i, j;
    int pivot;

    //Mid_pivot(arr, low, high);

    //pivot = arr[low];

    i = low;
    j = high;

    if(low > high)
        return;

    if(high - low + 1 < 4)
    {
        Insert_Sort(arr, low, high);
    }

    pivot = arr[low];

    while( i < j )
    {
        while(i < j && arr[j] >= pivot)
        {
            j--;
        }
        if(arr[j] < pivot)// && i != j)
            arr[i] = arr[j];

        while(i < j && arr[i] <= pivot)
        {
            i++;
        }
        if(arr[i] > pivot)// && i != j)
            arr[j] = arr[i];

        //swap(&arr[i], &arr[j]);

    }
    arr[i] = pivot;
    int mid = i;
    Q_sort(arr, low, mid - 1 );
    Q_sort(arr, mid + 1, high);

}

int main( int argc, int *argv[])
{
    int i, length;

    printf("Please enter 10 number: \n");
    for(i = 0; i < N/10;i++)
    {
        scanf("%d", &arr[i]);
    }
    //length = sizeof(arr) / sizeof(arr[0]);
    //printf("%d", length);

    Q_sort(arr, 0, N/10 - 1);

    printf("\n");
    for(i = 0; i < N/10;i++)
    {
        printf("%4d", arr[i]);
    }

    return 0;

}
