#include <stdio.h>
#include "vector.h"
#include <math.h>
//#include "union_find.h"

int main() {
    Vector *v = vector_construct();

    int n;
    scanf("%d", &n);

    int i;
    for (i = 0; i < n; i++) {
        vector_push_back(v, i);
    }

    int c;
    for (i = 2; i < sqrt(n); i++) {
        if (vector_get(v, i) == -1) continue;

        c = i;
        while (1)
        {
            c += i;
            if (c >= n) break;
            //printf("%d\n", c);
            vector_set(v, c, -1);
        }
        
    }

    for (i = 2; i < n; i++) {
        c = vector_get(v, i);
        if (c == -1) continue;
        printf("%d ", c);
    }

    printf("\n");

    vector_destroy(v);

    return 0;
}

/*
int main() {
    int N;
    scanf("%d", &N);

    UF *uf = UF_init(N);

    int i;
    for (i = 2; i < N; i++) {
        for (int c = i + 1; i < N; i++) {
            if (UF_find(uf, c) % UF_find(uf, i) == 0) {
                UF_union(uf, c, i);
            }
        }

        for (int p = i + 2; i < N; i++) {
            if (UF_find(uf, p) != i) {
                i = p;
                break;
            }
        }
    }

    for (i = 2; i < N; i++) {
        if (i == UF_find(uf, i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    UF_destroy(uf);

    return 0;
}
*/