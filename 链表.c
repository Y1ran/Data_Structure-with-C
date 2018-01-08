/**Linking Table**


****线性表之单向链表*****/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <process.h>
#include <stdbool.h>
#define N 10

struct node{
    int value;
    struct node *next; //声明一个NODE类型的结构标记
};

//在链表开始处插入节点

struct node *add_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node)); //利用MALLOC为新节点分配内存单元
    if (new_node == NULL){
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node ->value = n;
    new_node ->next = list;

    return new_node;
};

//遍历打印链表
void PrintList(struct node *h)
{
 struct node *p;

    for( p = h ;p != NULL;p = p->next)
    {
        printf("The node is:%d\n",p->value);

        //printf("Next node is:%d\n ",p->value);
    }
};


//利用ADD_LIST创建一个含有用户录入的链表
struct node *read_numbers(void)
{
    struct node *first = NULL;
    int n;

    printf("Enter a number and end with 0\n");
    for(;;){
        scanf("%d\n", &n);
        if(n != 0)
           // return first; 判断是否终止输入
        first = add_list(first, n);
        else{
            printf("End of Input\n");
            printf("\n");
            break;
            }
        }
    PrintList(first);
    };


//删除链表
struct node *delete_list(struct node *list, int n)
{
    struct node *cur, *prev;

    for( cur = list, prev = NULL;
        cur != NULL && cur->value != n;
        prev = cur, cur = cur->next);

    if(cur == prev)
        return list;
    if (prev == NULL)
        list = list->next;
    else
        prev->next = cur->next;

    free(cur);  //释放被删除节点的内存

    return list;
};



int main(int argc, char *argv[]){

read_numbers();


        return 0;

/*插入数据测试，经过测试封装为上面的函数直接调用
struct node *first = NULL;  //声明起始位置（为空）

first = add_list(first, 10);
first = add_list(first, 20);  插入数据测试
first = add_list(first, 30);

PrintList(first);
read_numbers();*/
};

