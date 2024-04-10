#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Deque
{
    Node *start;
    Node *end;
} Deque;

Node *get_node(int data)
{
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void insert_start(Deque *dq, int data)
{
    Node* new_node = get_node(data);
    if (dq->start == NULL) dq->start = dq->end = new_node;
    else {
        new_node->next = dq->start;
        dq->start->prev = new_node;
        dq->start = new_node;
    }
}

void insert_end(Deque *dq, int data)
{
    Node* new_node = get_node(data);
    if (dq->end == NULL) dq->start = dq->end = new_node;
    else {
        new_node->prev = dq->end;
        dq->end->next = new_node;
        dq->end = new_node;
    }
}

void remove_end(Deque *dq)
{
    if (dq->end != NULL)
    {
        Node* temp = dq->end;
        dq->end = dq->end->prev;
 
        if (dq->end == NULL) dq->start = NULL;
        else dq->end->next = NULL;
        free(temp);
    }
}

void dq_to_arr(Deque *dq, int *arr)
{
    Node *nd = dq->start;
    int i = 0;
    while (nd)
    {
        free(nd->prev);
        arr[i++] = nd->data;
        nd = nd->next;
    }
}

int cmp(const void * a, const void * b)
{
   return *(int*)b - *(int*)a;
}

int* deckRevealedIncreasing(int* deck, int size, int* ret_size)
{
    int *arr = (int *) malloc(size * sizeof(int));
    memcpy(arr, deck, size * sizeof(int));
    qsort(arr, size, sizeof(int), cmp);

    Deque *dq = (Deque *) malloc(sizeof(Deque));
    dq->start = NULL;
    dq->end = NULL;

    for (int i = 0; i < size; i++)
    {
        if (dq->end != NULL)
        {
            insert_start(dq, dq->end->data);
            remove_end(dq);
        }
        insert_start(dq, arr[i]);
    }

    dq_to_arr(dq, arr);
    free(dq);

    *ret_size = size;
    return arr;
}
