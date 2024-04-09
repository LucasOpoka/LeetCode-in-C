int maxDepth(char* s)
{
    int i=0, max=0;
    int ll, rl, rr, lr;
    while(s[i])
    {
        ll=0, rl=0, rr=0, lr=0;
        for (int j=i; j>=0; j--){
            if (s[j]=='(') ll++;
            if (s[j]==')') rl++;
        }
        for (int k=i+1; s[k]; k++){
            if (s[k]=='(') lr++;
            if (s[k]==')') rr++;
        }
        if ((ll-rl)==(rr-lr) && ll-rl>max) max = ll-rl;
        i++;
    }
    return max;
}
