#include <stdlib.h>

char* removeKdigits(char* str, int k)
{
    int n = strlen(str);
    int i = 0, j = 0;
    char *stc = (char*) calloc(n + 1, sizeof(char));

    if (k >= n) return "0";

    while (str[i])
    {
        while (j > 0 && stc[j - 1] > str[i] && k>0)
        {
            j--;
            k--;
        }
        stc[j++] = str[i++];
    }

    stc[j] = 0;

    // If needed remove from end
    for (k; k > 0; k--) stc[j-- - 1] = 0;

    // Skip 0s in front
    for (i = 0; stc[i] == 48; i++);

    return stc[i] == 0 ? "0" : &stc[i];
}
