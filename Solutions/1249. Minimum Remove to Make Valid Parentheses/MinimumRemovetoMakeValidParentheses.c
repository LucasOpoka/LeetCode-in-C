typedef struct
{
    int *arr;
    int top;
} Stack;

void push(Stack *st, int v) {st->arr[++st->top] = v;}
void pop (Stack *st) {st->arr[st->top--];}

char* minRemoveToMakeValid(char* s)
{
    int i = 0, j = 0;
    Stack stck;
    int arr[100000];

    stck.arr = arr;
    stck.top = -1;

    while (s[i])
    {
        if (s[i] == '(') push(&stck, i);
        else if (s[i] == ')')
        {
            if (!(stck.top == -1)) pop(&stck);
            else s[i] = '*';
        }
        i++;
    }

    i = stck.top;
    while (i >= 0 ) s[stck.arr[i--]] = '*';

    i = 0;
    while (s[j])
    {
        if (s[j] != '*') s[i++] = s[j];
        j++;
    }
    s[i] = 0;

    return s;    
}
