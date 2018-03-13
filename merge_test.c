/**test for Merge_sort
**/

//2018.03.10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef N
#define N 100
#endif // N

void Merge_Arr(int left, int mid, int right);
void Merge_sort(int m, int n);
int *tmp[N], *arr[N];

void Merge_Arr(int left, int mid, int right){
    int i, j, k;

    i = left;
    j = mid + 1;
    k = left;


    while(i <= mid && j <= right)
    {
        if(arr[i] < arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    while(i <= mid)
        tmp[k++] = arr[i++];

    while(j <= right)
        tmp[k++] = arr[j++];



    for (i = left; i <= right; i++)
    {
        arr[i] = tmp[i];
        printf("%5d", arr[i]);
    }

    printf("\n");

}

void Merge_sort(int m, int n)
{

    int mid;
    if(m < n){
        mid = (m + n) / 2;
        Merge_sort(m, mid);
        Merge_sort(mid + 1, n);
        Merge_Arr(m, mid, n);
    }
}

int main(int argc, int *argv[])
{
    int i, k;
    printf("enter number total: \n");
    scanf("%d", &k);

    printf("enter number for sort: \n");
    for( i = 1; i <= k; ++i)
    {
        scanf("%d", &arr[i]);
    }

    Merge_sort(1, k);
    printf("in order of::");

    for( i = 1; i <= k; ++i)
    {
        printf("%4d", arr[i]);
    }
}
