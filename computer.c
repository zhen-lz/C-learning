#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct suffix
{
    int number;
    char symbol;
};
struct suffix expre[MAX];
int data[MAX];
char symbol[MAX];
int Top1 = -1, Top2 = -1;
int sfix = -1;
int isFull(int n);
int isEmpty(int n);
void error(char *s);
void push_data(int n);
int pop_data();
void push_char(char c);
char pop_char();
int superior(char temp, char c);

int main()
{
    //for data input and into suffix expression//
    char input[256];
    gets(input);
    char c;
    int i = 0;
    c = input[i];
    while (c != '=')
    {
        if (c <= '9' && c >= '0')
        {
            int temp = 0;
            for (; input[i] <= '9' && input[i] >= '0'; i++)
            {
                temp = temp * 10 + c - '0';
            }
            expre[++sfix].number = temp;
            expre[sfix].symbol = 0;
            c = input[i];
        }
        else
        {
            char temp;
            if (isEmpty(Top2))
            {
                temp = c;
                push_char(temp);
            }
            else
            {
                if (c == '(')
                {
                    temp = c;
                    push_char(temp);
                }
                else if (c == ')')
                {
                    temp = pop_char();
                    while (temp != '(')
                    {
                        expre[++sfix].symbol = temp;
                        if (isEmpty(Top2))
                            break;
                        else
                            temp = pop_char();
                    }
                }
                else
                {
                    temp = pop_char();
                    while (superior(temp, c))
                    {
                        expre[++sfix].symbol = temp;
                        if (isEmpty(Top2))
                        {
                            push_char(temp);
                            break;
                        }
                        else
                        {
                            temp = pop_char();
                        }
                    }
                    if (isEmpty(Top2))
                    {
                        push_char(c);
                    }
                    else
                    {
                        push_char(temp);
                        push_char(c);
                    }
                }
            }
            c = input[++i];
        }
    }
    while (~isEmpty(Top2))
    {
        char c;
        c = pop_char();
        expre[++sfix].symbol = c;
    }
    return 0;
}
int superior(char temp, char c)
{
    if (temp == '(')
        return 0;
    else if (temp == '+' || temp == '-')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int isFull(int n)
{
    return n == MAX - 1;
}
int isEmpty(int n)
{
    return n == -1;
}
void error(char *s)
{
    printf("%s", s);
    exit(-1);
}
void push_data(int n)
{
    if (isFull(Top1))
    {
        error("Full!");
    }
    else
    {
        data[++Top1] = n;
    }
}
int pop_data()
{
    if (isEmpty(Top1))
    {
        error("Empty!");
        return 0;
    }
    else
    {
        return data[Top1--];
    }
}
void push_char(char c)
{
    if (isFull(Top2))
    {
        error("Full!");
    }
    else
    {
        symbol[++Top2] = c;
    }
}
char pop_char()
{
    if (isEmpty(Top2))
    {
        error("Empyt!");
        return 0;
    }
    else
    {
        return symbol[Top2--];
    }
}
