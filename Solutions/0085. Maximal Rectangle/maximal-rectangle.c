#define min(a,b) ((a <= b) ? (a) : (b))
#define max(a,b) ((a >= b) ? (a) : (b))

int maximalRectangle(char **arr, int rw, int *cl)
{
    int res = 0, max_l, min_r;
    if (rw==0 || *cl==0) return 0;

    int *lt = (int*) malloc(*cl * sizeof(int)); //left
    int *ht = (int*) malloc(*cl * sizeof(int)); //height
    int *rt = (int*) malloc(*cl * sizeof(int)); //right
    for (int i = 0; i < *cl; i++) {
        lt[i] = 0;
        ht[i] = 0;
        rt[i] = *cl;
    }

    for (int r = 0; r < rw; r++) {
        max_l = 0, min_r = *cl;
        //update height and left (left to right) 
        for (int c = 0; c < *cl; c++) {
            if (arr[r][c] == '1') {
                ht[c] += 1;
                lt[c] = max(max_l, lt[c]);
            }
            else {
                ht[c] = 0;
                lt[c] = 0;
                max_l = c+1;
            }
        }
        //update right (right to left)
        for (int c = *cl - 1; c > -1; c--) {
            if (arr[r][c] == '1') rt[c] = min(min_r, rt[c]);
            else {
                rt[c] = *cl;
                min_r = c;
            }
        }
        for (int c=0; c<*cl; c++) res = max(res, ht[c]*(rt[c]-lt[c]));
    }

    free(ht);
    free(lt);
    free(rt);
    return res;
}
