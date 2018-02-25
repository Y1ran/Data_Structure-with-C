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

struct binary_tree{
    int data;
    struct binary_tree *Lchild;
    struct binary_tree *Rchild;
};
typedef struct binary_tree BNode;




/**1.二叉树的先序递归创建**/

int CreateTree( BNode **Root);//此处使用
int CreateTree( BNode **Root)
{
    int Inp;
    int i = 0;
    for( Inp = 0; i < 10; i++)
    {
        scanf("%d", Inp);
        *Root = NULL;

    if(1)
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
    }

    return 1;
}

void insert(BNode **Tree, int val)
{
    BNode *new_root = NULL;
    if((*Tree) == NULL)
    {
        BNode *new_root = NULL;
        new_root =(BNode *)malloc(sizeof(BNode));
        new_root->Lchild = NULL;   //make sure
        new_root->Rchild = NULL;
        new_root->data = val;

        *Tree = new_root; //give new root to tree
        return;
    }

    if (val < (*Tree)->data)
    {
        //make sure left always less than right
        insert(&(*Tree)->Lchild, val);
    }
    else if ( val > (*Tree)->data)
    {
        insert(&(*Tree)->Rchild, val);
    }
    else
        printf("Please do not enter same number twice");
}


void delete_tree( BNode *Tree)
{
    if(Tree)
    {
        delete_tree(Tree->Lchild);
        delete_tree(Tree->Rchild);
        free(Tree);
    }
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
        printf("%d\n", Root->data);
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
        printf("%d\n",Root->data);
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
        printf("%d\n",Root->data);
    }
}

/**5. 二叉树的shendu**/

int max(int x, int y)
{
    return x>y? x:y;
}

int TreeDeep(BNode *Root)
{

    if(Root == NULL)
        return 0;
    else
        return max(TreeDeep(Root->Lchild) + 1, TreeDeep(Root->Rchild) + 1);
}
    //return deep;

void insert2(BNode ** tree, int val) {
    BNode * temp = NULL;
    if(!(*tree)) {
        temp = (BNode *)malloc(sizeof(BNode));
        temp->Lchild = temp->Rchild = NULL;
        temp->data = val;
        *tree = temp;
        return ;
    }

    if (val < (*tree)->data) {
        insert(&(*tree)->Lchild,val);
    }else if (val > (*tree)->data) {
        insert(&(*tree)->Rchild,val);
    }
}

/**6. leaf**/


/**ceshi Main**/



int main(int argc, const int *argv[])
{
    BNode * root;
    BNode * tmp;
    //int i;

    root = NULL;
//    root = NULL;

 //    Inserting nodes into tree
    insert(&root,9);
    insert(&root,4);
    insert(&root,15);
    insert(&root,6);
    insert(&root,12);
    insert(&root,17);
    insert(&root,2);

    printf("Pre Order Display\n");
    PreTrav(root);

    printf("In Order Display\n");
    MidTrav(root);

    printf("Post Order Display\n");
    PostTrav(root);

    int deep;
    printf("tree depth is\n %d", TreeDeep(root));

//    Deleting all nodes of tree
    delete_tree(root);
}

