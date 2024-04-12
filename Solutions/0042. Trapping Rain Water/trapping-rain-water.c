#define max(a, b) ((a >= b) ? (a) : (b))

int trap(int* arr, int size)
{
    int i = 0, j = size-1, res = 0, lmax=arr[i], rmax=arr[j];
    
    while (i < j)
    {
        if (lmax <= rmax)
        {
            i++;
            res += max(lmax - arr[i], 0);
            lmax = arr[i] > lmax ? arr[i] : lmax;
        }
        else
        {    
            j--;
            res += max(rmax - arr[j], 0);
            rmax = arr[j] > rmax ? arr[j] : rmax;
        }
    }
    return res;
}
