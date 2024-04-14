typedef struct num {
    int value;
    int count;
} num;

int hash(int value, int size) {
    //return index in range 0 to size-1
    return (value % size + size) % size;
}

int check_tab(num *tab, int size, int value)
{
    int index = hash(value, size);
    while (tab[index].value != value && tab[index].count != 0) {
        index = (index + 1) % size;
    }
    tab[index].value = value;
    return ++tab[index].count;
}
bool containsDuplicate(int* arr, int size)
{
    num *tab = (num*) calloc(size, sizeof(num));
    for (int i=0; i<size; i++) {
        if (check_tab(tab, size, arr[i]) > 1) {
            free(tab);
            return true;
        }
    }
    free(tab);
    return false;
}
