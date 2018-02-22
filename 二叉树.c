/**二叉树的创建与各种遍历**/

//采用最简单的递归形式

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//#undef NULL
//#define NULL ((void *)0)


#ifndef  End
#define End -1 //判断终止输入条件
#endif // End
/**0.树的结构**/

typedef struct BNode{
    int data;
    struct BNode *Lchild;
    struct BNode *Rchild;
}BNode;



/**1.二叉树的先序递归创建**/

int CreateTree( BNode **Root);//此处使用
int CreateTree( BNode **Root)
{
    int Inp;
    scanf("%d", &Inp);

    if( Inp == -1)
    {
        *Root = NULL;
        //return 0;
    }
    else
    {
        *Root = (BNode *)malloc(sizeof(BNode));
        if (Root == NULL)
        {
            printf("Failed\n");
            return 0;
        }
        else
        {
            (*Root)->data = Inp;
            CreateTree(&((*Root)->Lchild));
            printf("%d", Inp);
            CreateTree(&((*Root)->Rchild));
        }
    }

    return 1;
}

/**2. 二叉树的先序遍历**/

void PreTrav(BNode *Root)
{
    if( Root == NULL)
    {
        return;
    }
    else
    {
        printf("%d:", Root->data);
        PreTrav(Root->Lchild);
        PreTrav(Root->Rchild);
    }
}

/**3. 二叉树的中序遍历**/

void MidTrav(BNode *Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        MidTrav(Root->Lchild);
        printf("%d ",Root->data);
        MidTrav(Root->Rchild);
    }
}

/**4. 二叉树的后序遍历**/

void PostTrav(BNode *Root)
{
    if (Root == NULL)
    {
        return;
    }
    else
    {
        PostTrav(Root->Lchild);
        PostTrav(Root->Rchild);
        printf("%d ",Root->data);
    }
}

/**5. 二叉树的shendu**/

int TreeDeep(BNode *Root)
{
    int deep = 0;
    if (Root != NULL)
    {
        int leftdeep = TreeDeep(Root->Lchild);
        int rightdeep = TreeDeep(Root->Rchild);

        if( leftdeep >= rightdeep)
        {
            leftdeep++;
        }
        else
            rightdeep++;

    }

    return deep;
}

/**6. leaf**/


/**ceshi Main**/
int main(int argc,const char *argv[])
{
    BNode *Root;
    int depth,leafCount = 0;
    printf("Please enter the first elements for Tree：\n");
    CreateTree(&Root);

    printf("Traverse BiTree in PreOder：");
    PreTrav(Root);
    printf("\n");

    printf("Traverse BiTree in MidOder：");
    MidTrav(Root);
    printf("\n");

    printf("Traverse BiTree in Postoder：");
    PostTrav(Root);
    printf("\n");

    depth = TreeDeep(Root);
    printf("The depth of the tree is：%d\n",depth);



    return 0;
}
