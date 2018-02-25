#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
typedef struct BTNode
{
    int data;
    struct BTNode *Lchild,*Rchild;
}BTree;
//��ʼ��
BTree * Ini_BTNode()
{
    BTree *bt ;
    int a;
    bt=(BTree *)malloc(sizeof(BTree));
    printf("������ڵ㣺��0��ʾ������\n");
    scanf("%d",&a);
    if(a==0)
    {
        printf("���ǿ�����");
        exit(0);
    }
    bt->data=a;
    bt->Lchild=NULL;  //�������ڵ�
    bt->Rchild=NULL;  //�������ڵ�
    return bt;
}
creat_BiTree(BTree *bt)//����������
{

      int a;
      BTree *Node;
      printf("������%d�ڵ������(0Ϊ��)\n",bt->data) ;
      scanf("%d",&a);
      if(a!=0)
      {
              Node=(BTree*)malloc(sizeof(BTree));
              Node->data=a;
              Node->Lchild=NULL;
              Node->Rchild=NULL;
              bt->Lchild=Node;
              creat_BiTree(bt->Lchild);

      }
      printf("������%d�ڵ���Һ���(0Ϊ��)\n",bt->data) ; //����������
      scanf("%d",&a);
      if(a!=0)
      {
              Node=(BTree *)malloc(sizeof(BTree));
              Node->data=a;
              Node->Lchild=NULL;
              Node->Rchild=NULL;
              bt->Rchild =Node;
              creat_BiTree(bt->Rchild);

      }

      return 0;


}
void PerOrderTraverse(BTree *bt) //�������
{
    if(bt!=NULL)
   { printf("%d -->",bt->data);
     PerOrderTraverse(bt->Lchild);
     PerOrderTraverse(bt->Rchild);
   }
}
void InOrderTraverse(BTree *bt) //�������
{
    if(bt!=NULL)
   {
     InOrderTraverse(bt->Lchild);
     printf("%d -->",bt->data);
     InOrderTraverse(bt->Rchild);
   }
}
void PostOrderTraverse(BTree *bt) //�������
{
    if(bt!=NULL)
   {
     PostOrderTraverse(bt->Lchild);
     PostOrderTraverse(bt->Rchild);
     printf("%d -->",bt->data);
   }
}



main()
{
    BTree  *bt;
    int a;
    printf("\t\t****************  ����������  ****************\n\n");
    bt=Ini_BTNode();creat_BiTree(bt);
    printf("��%dΪ�����������ɹ���\n",bt->data);
    system("pause");
    system("cls");
    while(1)
    {

        system("cls");
        printf("\t\t1. �������\n");
        printf("\t\t2. �������\n");
        printf("\t\t3. �������\n");
        printf("\t\t4. �˳�����\n");
        printf("\t��ѡ��");
        scanf("%d",&a);
        switch(a)
        {
         case 1:printf("�������\n");
                PerOrderTraverse(bt);
                printf("\n");
                system("pause"); break;
         case 2:printf("�������\n");
                 InOrderTraverse(bt);
                 printf("\n");
                system("pause"); break;


         case 3:printf("�������\n");
                 PostOrderTraverse(bt);
                 printf("\n");
                system("pause"); break;
         case 4:exit(0);
         default:printf("�������");
        }

     }
  system("pause");
}
