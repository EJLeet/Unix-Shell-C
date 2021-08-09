#include "include.h"
#include "stack.h"

bool operand(char c) {return isdigit(c);} // check if symbol or operand

void calc(char *expression[], int counter)
{
    struct Stack* stack = createStack(counter); // create stack for expression

    for (int i = counter - 1; i > 0; i--)
    {// loop through the amount of args
        if (operand(*expression[i])) // push to stack if no operand
            push(stack, atoi(expression[i]));
        else
        {// operand encountered
            double a = head(stack); // pop last two digits from stack
            pop(stack);
            double b = head(stack);
            pop(stack);
            if (strcmp(expression[i], "+") == 0) push(stack, (a + b)); // perform addition or subtraction and push result to stack
            else push(stack, (a - b));
        }
    }
    printf("%d\n", head(stack)); // print result
}

