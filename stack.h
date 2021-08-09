#ifndef STACK_STRUCT
#define STACK_STRUCT

#include <stdlib.h>
#include <limits.h>

struct Stack
{ // define structure
    int top;
    unsigned size;
    int *array;
};

struct Stack *createStack(unsigned size)
{ // create stack of given size - initially 0
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int *)malloc(stack->size * sizeof(int));
    return stack;
}

int isFull(struct Stack *stack) { return stack->top == stack->size - 1; } // check if stack full - used by push

int isEmpty(struct Stack *stack) { return stack->top == -1; } // check if stack is empty - used by pop

void push(struct Stack *stack, int item)
{ // add item to stack
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{ // remove item from stack
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

int head(struct Stack *stack)
{ // return top of stack
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

#endif