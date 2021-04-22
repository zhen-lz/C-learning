#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line
{
    int x;
    int y;
    int code;
};
void sort(struct line fdot[], struct line ldot[], int num);
int find(struct line p, struct line fdot[], int num);

int main()
{
    int num;
    scanf("%d", &num);
    struct line fdot[num + 5];
    struct line ldot[num + 5];
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %d %d", &fdot[i].x, &fdot[i].y, &ldot[i].x, &ldot[i].y);
        fdot[i].code = 0;
        ldot[i].code = 0;
    }
    sort(fdot, ldot, num);
    int length = 1, maxlength = 0;
    struct line maxbegin;
    for (int i = 0; i < num; i++)
    {
        if (fdot[i].code == 0)
        {
            struct line p;
            p = ldot[i];
            fdot[i].code = 1;
            int temp;
            while ((temp = find(p, fdot, num)) != -1)
            {
                length++;
                fdot[temp].code = 1;
                p = ldot[temp];
            }
            if (length > maxlength)
            {
                maxlength = length;
                maxbegin = fdot[i];
                length = 1;
            }
            else
            {
                length = 1;
            }
        }
    }
    printf("%d ", maxlength);
    printf("%d %d", maxbegin.x, maxbegin.y);
    return 0;
}

void sort(struct line fdot[], struct line ldot[], int num)
{
    int i, j;
    for (i = 0; i < num; i++)
    {
        int cont = 0;
        for (j = 0; j < num - i - 1; j++)
        {
            if (fdot[j].x > fdot[j + 1].x)
            {
                struct line temp;
                temp = fdot[j];
                fdot[j] = fdot[j + 1];
                fdot[j + 1] = temp;
                temp = ldot[j];
                ldot[j] = ldot[j + 1];
                ldot[j + 1] = temp;
            }
            else
                cont++;
        }
        if (cont == num - i - 1)
            break;
    }
}

int find(struct line p, struct line fdot[], int num)
{
    int i = 0;
    for (; i < num; i++)
    {
        if (p.x == fdot[i].x && p.y == fdot[i].y)
            return i;
    }
    return -1;
}