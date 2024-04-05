#include <string.h>
#define abs(x) ((x)<0 ? -(x) : (x))

void rm_2char(char *s, int i)
{
    memmove(&s[i], &s[i + 2], strlen(s) - i - 1);
}

char* makeGood(char* s)
{
    int i = 0;

    while (i < strlen(s))
    {
        if (abs(s[i] - s[i + 1]) == 32)
        {
            rm_2char(s, i);
            if (i > 0) i--;
        }
        else i++;
    }
    return s;
}
