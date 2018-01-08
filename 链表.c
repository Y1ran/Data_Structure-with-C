/**Linking Table**


****���Ա�֮��������*****/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <process.h>
#include <stdbool.h>
#define N 10

struct node{
    int value;
    struct node *next; //����һ��NODE���͵Ľṹ���
};

//������ʼ������ڵ�

struct node *add_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node)); //����MALLOCΪ�½ڵ�����ڴ浥Ԫ
    if (new_node == NULL){
        printf("Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node ->value = n;
    new_node ->next = list;

    return new_node;
};

//������ӡ����
void PrintList(struct node *h)
{
 struct node *p;

    for( p = h ;p != NULL;p = p->next)
    {
        printf("The node is:%d\n",p->value);

        //printf("Next node is:%d\n ",p->value);
    }
};


//����ADD_LIST����һ�������û�¼�������
struct node *read_numbers(void)
{
    struct node *first = NULL;
    int n;

    printf("Enter a number and end with 0\n");
    for(;;){
        scanf("%d\n", &n);
        if(n != 0)
           // return first; �ж��Ƿ���ֹ����
        first = add_list(first, n);
        else{
            printf("End of Input\n");
            printf("\n");
            break;
            }
        }
    PrintList(first);
    };


//ɾ������
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

    free(cur);  //�ͷű�ɾ���ڵ���ڴ�

    return list;
};



int main(int argc, char *argv[]){

read_numbers();


        return 0;

/*�������ݲ��ԣ��������Է�װΪ����ĺ���ֱ�ӵ���
struct node *first = NULL;  //������ʼλ�ã�Ϊ�գ�

first = add_list(first, 10);
first = add_list(first, 20);  �������ݲ���
first = add_list(first, 30);

PrintList(first);
read_numbers();*/
};

