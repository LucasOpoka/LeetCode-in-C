int islandPerimeter(int** arr, int rows, int* cols)
{
    int res = 0;
    for (int r=0; r<rows;r++) {
        for (int c=0; c<*cols;c++) {
            if (arr[r][c]==1) {
                res += 4;
                if (r>0 && arr[r-1][c]==1) res -= 2;
                if (c>0 && arr[r][c-1]==1) res -= 2;
            }
        }
    }
    return res; 
}
