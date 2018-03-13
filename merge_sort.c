/**merge_sort**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef N1
#define N1 100
#endif // N

//int tmp[N], arr[N];

void Merge_sort(int *arr,int *tmp, int left, int right);
void Merge_arr(int *arr,int *tmp, int left, int mid, int right);

void Merge_arr(int *arr,int *tmp, int left, int mid, int right)
{
    int i,j,k;
    i = left;
    j = mid + 1;

    k = 0;
    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    while( i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while ( j <= right)
    {
        tmp[k++] = arr[j++];
    }

    for(i = 0; i < k; i++)
    {
        arr[left + i] = tmp[i];
        printf("%5d", arr[i]);
    }

    printf("\n");
}

void Merge_sort(int *arr,int *tmp, int left, int right)
{
    if( left < right)
    {
        int mid;
        mid = (left + right) / 2;
        Merge_sort(arr, tmp, left, mid);
        Merge_sort(arr, tmp, mid+1,right);
        Merge_arr(arr, tmp, left, mid, right );
    }
}

int main(int argc, int *argv[])
{
    int i, num;

    printf("Please enter the amount:\n");
    scanf("%d", &num);
    int arr[num], tmp[num];

    int N = num - 1;

    printf("Please enter the number:\n");
    for(i = 0; i <= N; i++)
    {
        scanf("%d", &arr[i]);
    }

    Merge_sort(arr, tmp, 0, N);
    printf("In order of:\n");
    for(i = 0; i <= N; i++)
    {
        printf("%4d", arr[i]);
    }
}
