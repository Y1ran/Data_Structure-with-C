/***Stack***

***ջ�ļ���ʵ��***/

//����ADT������������ʵ�ֳ���ջ
//����������������ַ�ʽ


/***��̬����ʵ��ջ������������**/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack_type
{
    item *contents;
    int top;
    int size;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}
