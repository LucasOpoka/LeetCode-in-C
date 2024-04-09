#define abs(x) ((x)<0 ? -(x) : (x))

int countStudents(int* stdt, int stdtS, int* sndw, int sndwS)
{
    int i = 0, j = 0;
    int count[2] = {0}; // 0 - circle stdnts, 1 - square stdnts
    while (i < stdtS) count[stdt[i++]]++;

    while (j < sndwS)
    {
        if (count[sndw[j]] > 0) count[sndw[j]]--;
        else return count[abs(sndw[j] - 1)];
        j++;
    }
    return 0;
}
