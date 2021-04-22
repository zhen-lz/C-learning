#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top;

int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAXSIZE - 1;
}
void initStack()
{
    top = -1;
}
void push(int s[], int item)
{
    if (isFull())
    {
        printf("error ");
    }
    else
    {
        s[++top] = item;
    }
}
int pop(int s[])
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        return s[top--];
    }
}

int main()
{
    initStack();
    int item;
    scanf("%item", &item);
    while (item != -1)
    {
        switch (item)
        {
        case 1:
            scanf("%d", &item);
            push(stack, item);
            break;
        case 0:
            item = pop(stack);
            if (item == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ", item);
            }
            break;
        }
        scanf("%d", &item);
    }
    return 0;
}