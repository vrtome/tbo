#include "union_find.h"
#include <stdlib.h>


UF *UF_init(int N)
{
    UF *uf = (UF *) calloc(1, sizeof(UF));
    uf->array = (int *) calloc(N, sizeof(int));
    uf->capacity = N;

    int i;
    for (i = 0; i < N; i++)
    {
        uf->array[i] = i;
    }

    return uf;
}

void UF_union(UF *uf, int p, int q)
{
    int pid = UF_find(uf, p);
    int qid = UF_find(uf, q);
    int i;
    for (i = 0; i < uf->capacity; i++)
    {
        if (uf->array[i] == pid) uf->array[i] = qid;
    }
}

int UF_find(UF *uf, int p)
{
    return uf->array[p];
}

bool UF_connected(UF *uf, int p, int q)
{
    return (UF_find(uf, p) == UF_find(uf, q));
}

void UF_destroy(UF *uf)
{
    free(uf->array);
    free(uf);
}