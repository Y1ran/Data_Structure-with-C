#undef NULL

#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct BTNode{
    int data;
    struct BTNode *lChild;
    struct BTNode *rChild;
}BiTNode;


int CreateBiTree(BiTNode **T)
{
    int ch;
    scanf("%d",&ch);
    if (ch == -1)
    {
        *T = NULL;
        return 0;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        if (T == NULL)
        {
            printf("failed\n");
            return 0;
        }
        else
        {
            (*T)->data = ch;
            printf("����%d�����ӽڵ㣺",ch);
            CreateBiTree(&((*T)->lChild));
            printf("����%d�����ӽڵ㣺",ch);
            CreateBiTree((&(*T)->rChild));
        }
    }

    return 1;
}



//�������������
void PreOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",T->data);
        PreOrderBiTree(T->lChild);
        PreOrderBiTree(T->rChild);
    }
}




//�������������
void MiddleOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        MiddleOrderBiTree(T->lChild);
        printf("%d ",T->data);
        MiddleOrderBiTree(T->rChild);
    }
}




//��������������
void PostOrderBiTree(BiTNode *T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        PostOrderBiTree(T->lChild);
        PostOrderBiTree(T->rChild);
        printf("%d ",T->data);
    }
}



//�����������
int TreeDeep(BiTNode *T)
{
    int deep = 0;
    if (T != NULL)
    {
        int leftdeep = TreeDeep(T->lChild);
        int rightdeep = TreeDeep(T->rChild);
        deep = leftdeep >= rightdeep?leftdeep+1:rightdeep+1;
    }

    return deep;
}




//Ҷ�ӽڵ����
int LeafCount(BiTNode *T)
{
    static int count;
    if (T != NULL)
    {
        if (T->lChild == NULL && T->rChild == NULL)
        {
            count++;
        }

        LeafCount(T->lChild);
        LeafCount(T->rChild);
    }

    return count;
}





//������
int main(int argc,const char *argv[])
{
    BiTNode *T;
    int depth,leafCount = 0;
    printf("�������һ���ڵ��ֵ��-1��ʾû��Ҷ�ڵ㣺\n");
    CreateBiTree(&T);

    printf("���������������");
    PreOrderBiTree(T);
    printf("\n");

    printf("���������������");
    MiddleOrderBiTree(T);
    printf("\n");

    printf("����������������");
    PostOrderBiTree(T);
    printf("\n");

    depth = TreeDeep(T);
    printf("�������Ϊ��%d\n",depth);

    leafCount = LeafCount(T);
    printf("Ҷ�ӽڵ����:%d\n",leafCount);

    return 0;
}
