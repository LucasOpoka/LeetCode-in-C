int timeRequiredToBuy(int* tickets, int s, int k)
{
    int time = 0;

    while (tickets[k] != 0)
    {
        for (int i=0; i < s; i++)
        {
            if (tickets[i] > 0)
            {
                tickets[i]--;
                time++;
            }
            if (tickets[k] == 0) return time;
        }
    }
    return time;
}
