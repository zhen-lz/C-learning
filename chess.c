#include <stdio.h>

int heng(int in[][19], int c, int x, int y);
int you(int in[][19], int c, int x, int y);
int shu(int in[][19], int c, int x, int y);
int zuo(int in[][19], int c, int x, int y);

int main()
{
    int in[19][19] = {{0}};
    int i, j;
    for (i = 0; i < 19; ++i)
    {
        for (j = 0; j < 19; ++j)
        {
            scanf("%d", &in[i][j]);
        }
    }
    int win = 0;
    for (i = 0; i < 19; ++i)
    {
        for (j = 0; j < 19; ++j)
        {
            if (in[i][j] != 0)
            {
                win = heng(in, in[i][j], i, j);
                if (win != 0)
                {
                    printf("%d:", win);
                    printf("%d,%d\n", i + 1, j + 1);
                    return 0;
                }
                win = shu(in, in[i][j], i, j);
                if (win != 0)
                {
                    printf("%d:", win);
                    printf("%d,%d\n", i + 1, j + 1);
                    return 0;
                }
                win = zuo(in, in[i][j], i, j);
                if (win != 0)
                {
                    printf("%d:", win);
                    printf("%d,%d\n", i + 1, j + 1);
                    return 0;
                }
                win = you(in, in[i][j], i, j);
                if (win != 0)
                {
                    printf("%d:", win);
                    printf("%d,%d\n", i + 1, j + 1);
                    return 0;
                }
                win = 0;
            }
        }
    }
    printf("No\n");
    return 0;
}

int heng(int in[][19], int c, int x, int y)
{
    int num = 0;
    while (in[x][y] == c)
    {
        num++;
        y++;
    }
    if ((num == 4) && (in[x][y] == 0 || in[x][y - 5] == 0))
        return c;
    else
        return 0;
}

int shu(int in[][19], int c, int x, int y)
{
    int num = 0;
    while (in[x][y] == c)
    {
        num++;
        x++;
    }
    if ((num == 4) && (in[x][y] == 0 || in[x - 5][y] == 0))
        return c;
    else
        return 0;
}

int zuo(int in[][19], int c, int x, int y)
{
    int num = 0;
    while (in[x][y] == c)
    {
        num++;
        x++;
        y--;
    }
    if ((num == 4) && (in[x][y] == 0 || in[x - 5][y + 5] == 0))
        return c;
    else
        return 0;
}

int you(int in[][19], int c, int x, int y)
{
    int num = 0;
    while (in[x][y] == c)
    {
        num++;
        x++;
        y++;
    }
    if ((num == 4) && (in[x][y] == 0 || in[x - 5][y - 5] == 0))
        return c;
    else
        return 0;
}