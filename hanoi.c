#include <stdio.h>
void hanoi(int n, char x, char y, char z)
{
    if (n > 0)
    {
        hanoi(n - 1, x, z, y);
        printf("MOVE %d: %c -> %c\n", n, x, z);
        hanoi(n - 1, y, x, z);
    }
}
int main()
{
    int n;
    printf("Please input the number of hanoi tower:");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
}
