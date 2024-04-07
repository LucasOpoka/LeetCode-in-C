typedef struct node
{
	int *num;
	int *ind;
	struct node* next;
} node;

node *create_nd(void *data1, void *data2)
{
	node *new_nd = (node *) malloc(sizeof(node));
	new_nd -> num = data1;
	new_nd -> ind = data2;
	new_nd -> next = NULL;
	return new_nd;
}

node *go_to_end(node *llist_strt)
{
	while (llist_strt -> next != NULL)
    {
        llist_strt = llist_strt -> next;
    }
    return llist_strt;
}

void insrt_at_end(node **llist_strt, void *data1, void *data2)
{
	node *new_elem = create_nd(data1, data2);

	if (*llist_strt == NULL)
	{
		*llist_strt = new_elem;
	}
	else
	{
		go_to_end(*llist_strt) -> next = new_elem;	
	}
}

int hash(unsigned int n, int size)
{
    n = (n<0) ? -n : n;
    return n % size;
} 

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int size = numsSize * 2;
    int *res = (int*) malloc(2 * sizeof(int));
    node **htab = (node**) calloc(size, sizeof(node*));

    for (int i=0; i<size; i++)
    {
	    int rest = target - nums[i]; 
        int hsh = hash(rest,size);
     	
	    node *curr = htab[hsh];
        while(curr != NULL)
        {   
            if (*(curr->num) == rest)
            {
                res[0] = i;
                res[1] = *(curr->ind);
                *returnSize = 2;
                return res;
            }
            curr = curr->next;
        }
        
	    hsh = hash(nums[i],size);
		int *index = (int*) malloc(sizeof(int));
		*index = i;
        insrt_at_end(&htab[hsh],&nums[i],index);
    }
    return NULL;
}
