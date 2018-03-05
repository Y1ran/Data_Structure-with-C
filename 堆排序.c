
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//给定父节点的索引，得到左子节点的索引
#ifndef LeftChild(i)
#define LeftChild(i) (2*(i)+1)
#endif // LeftChild

//交换两个元素的位置
void _swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

//元素下沉方法
void PercDown(int A[], int i, int N)
{
    //子节点的索引号
    int child;
    //存储当前父节点元素的临时变量
    //(注：每一个节点都可以看作是其子树的根节点)

    for (; LeftChild(i) < N; i = child)
    {
        child = LeftChild(i);
        //挑选出左、右子节点中较大者
        if (child != N-1 && A[child+1]>A[child])
        {

            child++;
        }

        //比较当前父节点与较大子节点
        if (A[i] < A[child])
        {
            //交换当前父节点处的元素值与较大子节点的元素值
            /**tmp= A[i];
            A[i] = A[child];
            A[child] = tmp;
            **/
            _swap(&A[i], &A[child]);
        }
        else
        {
            break;
        }

    }
}

//堆排序
void HeapSort(int A[], int N)
{
    int i;
    //步骤一：创建大根堆
    for (i  = N/2;  i>=0; i--)
    {
        PercDown(A, i, N);

    }
    //步骤二：调整大根堆
    for ( i = N-1; i > 0; i--)
    {
         //首尾交换
        _swap(&A[0], &A[i]);
        //元素下沉
        PercDown(A, 0, i);
    }
}


//主函数
void main()
{
    //int A[6] = {4,5,3,2,6,1};

    register int i;
    int A[6];
    printf("Please enter the number to sort:\n");
    for(i = 0; i < 6; i++)
    {
        scanf("%d",&A[i]);
    }
    HeapSort(A, 6);
    printf("The rank is:\n");

    for(i = 0; i < 6; i++)
    {
        printf("%d\n",A[i]);
    }
}
