
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//�������ڵ���������õ����ӽڵ������
#ifndef LeftChild(i)
#define LeftChild(i) (2*(i)+1)
#endif // LeftChild

//��������Ԫ�ص�λ��
void _swap(int *num1, int *num2)
{
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

//Ԫ���³�����
void PercDown(int A[], int i, int N)
{
    //�ӽڵ��������
    int child;
    //�洢��ǰ���ڵ�Ԫ�ص���ʱ����
    //(ע��ÿһ���ڵ㶼���Կ������������ĸ��ڵ�)

    for (; LeftChild(i) < N; i = child)
    {
        child = LeftChild(i);
        //��ѡ�������ӽڵ��нϴ���
        if (child != N-1 && A[child+1]>A[child])
        {

            child++;
        }

        //�Ƚϵ�ǰ���ڵ���ϴ��ӽڵ�
        if (A[i] < A[child])
        {
            //������ǰ���ڵ㴦��Ԫ��ֵ��ϴ��ӽڵ��Ԫ��ֵ
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

//������
void HeapSort(int A[], int N)
{
    int i;
    //����һ�����������
    for (i  = N/2;  i>=0; i--)
    {
        PercDown(A, i, N);

    }
    //����������������
    for ( i = N-1; i > 0; i--)
    {
         //��β����
        _swap(&A[0], &A[i]);
        //Ԫ���³�
        PercDown(A, 0, i);
    }
}


//������
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
