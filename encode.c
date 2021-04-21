#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct secret
{
    char ch;
    struct secret *link;
};

int main()
{
    //输入密匙//
    char in_code[36] = {'\0'};
    char c;
    while (scanf("%c", &c) != EOF)
    {
        if ((strchr(in_code, c) == NULL) && (c >= 32) && (c <= 126))
            in_code[strlen(in_code)] = c;
    }
    //建立密环//
    int i;
    struct secret *first = NULL, *p, *q;
    for (i = 0; i < strlen(in_code); i++)
    {
        if (first == NULL)
        {
            p = (struct secret *)malloc(sizeof(struct secret));
            p->link = NULL;
            p->ch = in_code[i];
            first = p;
            q = p;
        }
        else
        {
            p = (struct secret *)malloc(sizeof(struct secret));
            p->link = NULL;
            p->ch = in_code[i];
            q->link = p;
            q = p;
        }
    }
    for (i = 32; i <= 126; i++)
    {
        c = i;
        if (strchr(in_code, c) == NULL)
        {
            p = (struct secret *)malloc(sizeof(struct secret));
            p->link = NULL;
            p->ch = c;
            q->link = p;
            q = p;
        }
    }
    q->link = first;
    //建立对应密码表//
    char code[100] = {'\0'};
    p = first;
    char head = first->ch;
    while (q->link != q)
    {
        q->link = p->link;
        c = p->ch;
        free(p);
        p = q->link;
        for (i = 1; i != c; i++)
        {
            p = p->link;
            q = q->link;
        }
        code[c - 32] = p->ch;
    }
    code[q->ch - 32] = head;
    //加密//
    FILE *in = fopen("in.txt", "r");
    FILE *out = fopen("in_crpyt.txt", "w");
    while (fscanf(in, "%c", &c) != EOF)
    {
        if (c >= 32 && c <= 126)
            fprintf(out, "%c", code[c - 32]);
        else
            fprintf(out, "%c", c);
    }
}