#include <stdio.h>
#include <string.h>

char buff[255];
char *strstr_lz(const char *str1, const char *str2);

int main()
{
    char in_c[10] = {'\0'}, out_c[10] = {'\0'};
    gets(in_c);
    gets(out_c);
    FILE *in = fopen("filein.txt", "r");
    FILE *out = fopen("fileout.txt", "w");
    char *p, *q;
    while (fgets(buff, 255, in) != NULL)
    {
        p = buff;
        while (strstr_lz(p, in_c) != NULL)
        {
            q = p;
            p = strstr_lz(p, in_c);
            *p = '\0';
            fprintf(out, "%s", q);
            fprintf(out, "%s", out_c);
            p = p + strlen(in_c);
        }
        if (p)
            fputs(p, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}
char *strstr_lz(const char *str1, const char *str2)
{
    char *cp = (char *)str1;
    char *s1, *s2;
    if (!*str2)
        return ((char *)str1);
    while (*cp)
    {
        s1 = cp;
        s2 = (char *)str2;
        while (*s1 && *s2 && (!(*s1 - *s2) || *s1 - *s2 == 32 || *s1 - *s2 == -32))
            s1++, s2++;
        if (!*s2)
            return (cp);
        cp++;
    }
    return (NULL);
}