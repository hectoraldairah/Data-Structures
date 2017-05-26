#include <stackset.h>
#include <stdio.h>
#include <string.h>


int isBalanced(char *string)
{
    Stack stack = empty();
    for (int i = 0; i < strlen(string); ++i)
    {
        char c = string[i];
        if (c == '{' || c == '[' || c == '(')
            push(&stack, c);
        else if (c == '}' || c == ']' || c == ')')
            if (isEmpty(stack))
            {
                puts("Is not balanced");
                break;
            }
            else
                stack = pop(stack);
    }

    if (!isEmpty(stack))
        puts("Is not balanced");
}

int isOperator(char c)
{
    return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}

int hierarchy(char c)
{
    if (c == '^')
        return 3;
    if (c == '*')
        return 2;
    if (c == '/')
        return 2;
    if (c == '+')
        return 1;
    if (c == '-')
        return 1;
}

void postFixExpression(char *string)
{
    Stack stack = empty();
    for (int i = 0; i < strlen(string); i++)
    {
        char c = string[i];
        if (!isOperator(c))
            printf("%c", c);
        else if (isEmpty(stack))
            push(&stack, c);
        else if (hierarchy(c) > hierarchy(top(stack)))
            push(&stack, c);
        else if (hierarchy(c) < hierarchy(top(stack)))
        {
            while (!isEmpty(stack))
            {
                printElem(top(stack));
                stack = pop(stack);
            }
            push(&stack, c);
        }
    }
    while (!isEmpty(stack))
    {
        printElem(top(stack));
        stack = pop(stack);
    }
}