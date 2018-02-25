#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"
typedef struct BTNode
{
    int data;
    struct BTNode *Lchild,*Rchild;
}BTree;
//初始化
BTree * Ini_BTNode()
{
    BTree *bt ;
    int a;
    bt=(BTree *)malloc(sizeof(BTree));
    printf("输入根节点：（0表示空树）\n");
    scanf("%d",&a);
    if(a==0)
    {
        printf("这是空树！");
        exit(0);
    }
    bt->data=a;
    bt->Lchild=NULL;  //左子树节点
    bt->Rchild=NULL;  //右子树节点
    return bt;
}
creat_BiTree(BTree *bt)//输入左子树
{

      int a;
      BTree *Node;
      printf("请输入%d节点的左孩子(0为空)\n",bt->data) ;
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
      printf("请输入%d节点的右孩子(0为空)\n",bt->data) ; //输入右子树
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
void PerOrderTraverse(BTree *bt) //先序遍历
{
    if(bt!=NULL)
   { printf("%d -->",bt->data);
     PerOrderTraverse(bt->Lchild);
     PerOrderTraverse(bt->Rchild);
   }
}
void InOrderTraverse(BTree *bt) //中序遍历
{
    if(bt!=NULL)
   {
     InOrderTraverse(bt->Lchild);
     printf("%d -->",bt->data);
     InOrderTraverse(bt->Rchild);
   }
}
void PostOrderTraverse(BTree *bt) //后序遍历
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
    printf("\t\t****************  二叉树操作  ****************\n\n");
    bt=Ini_BTNode();creat_BiTree(bt);
    printf("以%d为根的树创建成功！\n",bt->data);
    system("pause");
    system("cls");
    while(1)
    {

        system("cls");
        printf("\t\t1. 先序遍历\n");
        printf("\t\t2. 中序遍历\n");
        printf("\t\t3. 后序遍历\n");
        printf("\t\t4. 退出程序\n");
        printf("\t请选择：");
        scanf("%d",&a);
        switch(a)
        {
         case 1:printf("先序遍历\n");
                PerOrderTraverse(bt);
                printf("\n");
                system("pause"); break;
         case 2:printf("中序遍历\n");
                 InOrderTraverse(bt);
                 printf("\n");
                system("pause"); break;


         case 3:printf("后序遍历\n");
                 PostOrderTraverse(bt);
                 printf("\n");
                system("pause"); break;
         case 4:exit(0);
         default:printf("输入错误");
        }

     }
  system("pause");
}
