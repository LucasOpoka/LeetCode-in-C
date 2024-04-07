bool checkValidString(char* s)
{
    int i = 0, min = 0, max = 0;
    while (s[i])
    {
        if (s[i] == '(')        {min++; max++;}
        else if (s[i] == ')')   {min--; max--;}
        else                    {min--; max++;}
        if (max < 0) return false;
        min = (min < 0) ? 0 : min;
        i++;
    }
    return min == 0;
}
