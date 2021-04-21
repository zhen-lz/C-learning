#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct telbooks
{
    char name[30];
    char number[20];
};

int del(struct telbooks in[], int j, int cont)
{
    for (int i = j; i < cont; i++)
    {
        in[i] = in[i + 1];
    }
    return cont - 1;
}

int main()
{
    int cont;
    scanf("%d", &cont);
    struct telbooks in[cont + 5];
    for (int i = 0; i < cont; ++i)
        scanf("%s %s", in[i].name, in[i].number);
    struct telbooks temp;
    for (int i = 0; i < cont; ++i)
    {
        int num = 0;
        for (int j = 0; j < cont - i - 1; ++j)
        {
            if (strcmp(in[j].name, in[j + 1].name) > 0)
            {
                temp = in[j];
                in[j] = in[j + 1];
                in[j + 1] = temp;
            }
            else
            {
                num++;
            }
        }
        if (num == cont - i - 1)
            break;
    }
    //排序//
    for (int i = 0; i < cont - 1; ++i)
    {
        if (strcmp(in[i].name, in[i + 1].name) == 0)
        {
            if (strcmp(in[i].number, in[i + 1].number) == 0)
            {
                cont = del(in, i + 1, cont);
                i = i - 1;
            }
        }
    }
    //去重//
    for (int i = 0; i < cont - 1; ++i)
    {
        char s[3] = {'_', '0', '\0'};
        if (strcmp(in[i].name, in[i + 1].name) == 0)
        {
            int j = i + 1;
            for (; strcmp(in[i].name, in[j].name) == 0; j++)
            {
                s[1]++;
                strcat(in[j].name, s);
            }
        }
    }
    //标号//
    for (int i = 0; i < cont; ++i)
    {
        printf("%s %s\n", in[i].name, in[i].number);
    }
    return 0;
}