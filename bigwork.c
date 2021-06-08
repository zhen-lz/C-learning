#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stopwc
{
    char word[16];
    int cont;
} stopword[320];
char word[16];
struct sentencefreq
{
    char sentence[512];
    int num[1024];
    int frequency;
    struct sentencefreq *link;
};
typedef struct sentencefreq freq;
struct lz
{
    freq *fp;
    int frequency;
};
void strccat(char s[], char c);
void incode(int num[], int n);
int searchwl(char word[]);
void numset(int num[]);
void getin(struct lz stack[], int n, freq *p);

int main()
{
    /* get stop-word list */
    FILE *stopw_fp;
    int i = 0;
    stopw_fp = fopen("stopwords.txt", "r");
    while ((fscanf(stopw_fp, "%s", word)) != EOF)
    {
        strcpy(stopword[i].word, word);
        stopword[i].cont = 0;
        i++;
    }
    fclose(stopw_fp);
    /* statistic frequency */
    FILE *afp;
    afp = fopen("article.txt", "r");
    char c;
    freq *first = NULL;
    freq *p, *q;
    while (fscanf(afp, "%c", &c) != EOF)
    {
        if (isalpha(c))
        {
            memset(word, '\0', 16);
            i = 0;
            do
            {
                word[i] = c;
                fscanf(afp, "%c", &c);
                i++;
            } while (isalpha(c));
            int n;
            n = searchwl(word);
            if (first == NULL)
            {
                p = (freq *)malloc(sizeof(freq));
                numset(p->num);
                p->link = NULL;
                p->frequency = 0;
                memset(p->sentence, '\0', 512);
                strcat(p->sentence, word);
                strccat(p->sentence, c);
                incode(p->num, n);
                first = p;
                q = p;
                if (c == '.' || c == '!' || c == '?')
                {
                    p = (freq *)malloc(sizeof(freq));
                    numset(p->num);
                    p->link = NULL;
                    p->frequency = 0;
                    memset(p->sentence, '\0', 512);
                    q->link = p;
                }
            }
            else
            {
                if (c == '.' || c == '!' || c == '?')
                {
                    strcat(p->sentence, word);
                    strccat(p->sentence, c);
                    incode(p->num, n);
                    q = p;
                    p = (freq *)malloc(sizeof(freq));
                    numset(p->num);
                    p->link = NULL;
                    p->frequency = 0;
                    memset(p->sentence, '\0', 512);
                    q->link = p;
                }
                else
                {
                    strcat(p->sentence, word);
                    strccat(p->sentence, c);
                    incode(p->num, n);
                }
            }
        }
    }
    /* put out */
    struct lz stack[5];
    for (i = 0; i < 5; i++)
    {
        stack[i].frequency = 0;
        stack[i].fp = NULL;
    }
    p = first;
    while (p != NULL)
    {
        int n = 0;
        int i = 0;
        while (p->num[i] != -1)
        {
            n += stopword[p->num[i]].cont;
        }
        getin(stack, n, p);
    }

    return 0;
}

void getin(struct lz stack[], int n, freq *p)
{
    int i = 0;
    while (stack[i].frequency <= n)
    {
        if (stack[i].fp == NULL)
        {
            stack[i].fp = p;
            stack[i].frequency = n;
        }
        else
        {
        }
    }
}
void numset(int num[])
{
    for (int i = 0; i < 1024; i++)
    {
        num[i] = -1;
    }
}
int searchwl(char word[])
{
    char temp[16];
    int i = 0;
    for (; i < 16; i++)
    {
        temp[i] = tolower(word[i]);
    }
    /* find */
    i = 0;
    for (; i < 320; i++)
    {
        if (strcmp(stopword[i].word, temp) == 0)
        {
            stopword[i].cont++;
            return i;
        }
    }
    return -1;
}

void strccat(char s[], char c)
{
    int n;
    n = strlen(s);
    s[n] = c;
    s[n + 1] = '\0';
}

void incode(int num[], int n)
{
    int i;
    i = 0;
    if (n != -1)
    {
        while (num[i] != -1)
            i++;
        num[i] = n;
    }
}