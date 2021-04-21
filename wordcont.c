#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wordcont
{
    char word[25];
    int num;
    struct wordcont *link;
};

int issame(struct wordcont *p, char s[])
{
    int n = 1;
    for (; p != NULL; p = p->link)
    {
        if (strcmp(p->word, s) == 0)
        {
            p->num = p->num + 1;
            n = 0;
            break;
        }
    }
    return n;
}

int input(char s[], FILE *p)
{
    int i = 0;
    char c;
    if (fscanf(p, "%c", &c) == EOF)
    {
        return -1;
    }
    else
    {
        while (isalpha(c) == 0)
        {
            if (fscanf(p, "%c", &c) == EOF)
                break;
        }
        for (; isalpha(c) != 0; i++)
        {
            s[i] = tolower(c);
            if (fscanf(p, "%c", &c) == EOF)
                break;
        }
    }
    return 1;
}

int main()
{
    FILE *fp = fopen("article.txt", "r");
    struct wordcont *p, *q, *first = NULL;
    char inw[25] = {'\0'};
    while (input(inw, fp) != -1)
    {
        if (first == NULL)
        {
            p = (struct wordcont *)malloc(sizeof(struct wordcont));
            p->link = NULL;
            strncpy(p->word, inw, 25);
            p->num = 1;
            first = p;
        }
        else
        {
            if (issame(first, inw))
            {
                p = (struct wordcont *)malloc(sizeof(struct wordcont));
                p->link = NULL;
                strncpy(p->word, inw, 25);
                p->num = 1;
                if (strcmp(first->word, inw) > 0)
                {
                    p->link = first;
                    first = p;
                }
                else
                {
                    q = first;
                    while ((q->link != NULL) && (strcmp(q->link->word, inw) < 0))
                    {
                        q = q->link;
                    }
                    if (q->link == NULL)
                    {
                        q->link = p;
                    }
                    else
                    {
                        p->link = q->link;
                        q->link = p;
                    }
                }
            }
        }
        memset(inw, '\0', 25);
    }
    if (isalpha(first->word[0]) == 0)
        first = first->link;
    while (first != NULL)
    {
        printf("%s %d\n", first->word, first->num);
        first = first->link;
    }
    return 0;
}