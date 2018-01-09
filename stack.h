/***stack.h***/

#ifndef stack_h
#define stack_h

#include <stdbool.h>

typedef int item;

typedef struct stack_type *stack;

stack create(void);
void destroy(stack s);

void make_empty(stack s);
bool is_empty(stack s);
bool is_full(stack s);
void push(stack s, item i);
item opo (stack s);

#endif
