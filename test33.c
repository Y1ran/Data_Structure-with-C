#include "stdio.h"
#define MAX 100
int is1[MAX],is2[MAX];//原数组is1，临时空间数组is2
void merge(int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    while(i<=mid&&j<=high)
        if(is1[i]<is1[j])
            is2[k++]=is1[i++];
        else
            is2[k++]=is1[j++];
    while(i<=mid)
        is2[k++]=is1[i++];
    while (j<=high)
        is2[k++]=is1[j++];
    for ( i = low; i <=high ; i++) {
        is1[i]=is2[i];
        printf("%5d",is1[i]);
    }
    printf("\n");
}

void mergeSort(int a, int b){
    if(a<b){
        int mid=(a+b)/2;
        mergeSort(a,mid);
        mergeSort(mid+1,b);
        merge(a,mid,b);
    }
}

void main(){
    int i,n;
    printf("请输入元素个数：");
    scanf("%d",&n);
    printf("请依次输入每个元素：\n");
    for ( i = 1; i <=n ; ++i) {
        scanf("%d",&is1[i]);
    }
    mergeSort(1,n);
    printf("排序后的序列为：\n");
    for ( i = 1; i <=n ; ++i) {
        printf("%4d",is1[i]);
    }
}
