/***Stack***

***栈的几种实现***/

//利用ADT抽象数据类型实现抽象栈
//利用数组和链表两种方式


/***动态数组实现栈抽象数据类型**/

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
