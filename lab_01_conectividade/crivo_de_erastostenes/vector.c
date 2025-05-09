#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void _vector_validate_index(Vector *v, int i);
void _vector_deincrement_size(Vector *v, int i);

Vector *vector_construct() {
    Vector *v = (Vector *) calloc(1, sizeof(Vector));
    v->allocated = 10;
    v->data = (data_type *) calloc(v->allocated, sizeof(data_type));
    return v;
}

void vector_push_back(Vector *v, data_type val) {
    if (v->size == v->allocated) {
        v->allocated *= 2;
        v->data = (data_type *) realloc(v->data, v->allocated * sizeof(data_type));
    }

    v->data[v->size] = val;
    v->size++;
}

data_type vector_get(Vector *v, int i) {
    _vector_validate_index(v, i);
    return v->data[i];
}

void vector_set(Vector *v, int i, data_type val) {
    _vector_validate_index(v, i);
    v->data[i] = val;
}

int vector_size(Vector *v) {
    return v->size;
}

int vector_find(Vector *v, data_type val) {
    int i;
    for (i = 0; i < vector_size(v); i++) {
        if (vector_get(v, i) == val) {
            return i;
        }
    }

    return -1;
}

int vector_argmax(Vector *v) {
    int max_idx = 0, i;
    for (i = 0; i < vector_size(v); i++)
        if (vector_get(v, max_idx) < vector_get(v, i))
            max_idx = i;
    
    return max_idx;
}

int vector_argmin(Vector *v) {
    int min_idx = 0, i;
    for (i = 0; i < vector_size(v); i++)
        if (vector_get(v, i) < vector_get(v, min_idx))
            min_idx = i;
    
    return min_idx;
}

data_type vector_max(Vector *v) {
    data_type max;
    max = vector_get(v, vector_argmax(v));

    return max;
}

data_type vector_min(Vector *v) {
    data_type min;
    min = vector_get(v, vector_argmin(v));

    return min;
}

data_type vector_remove(Vector *v, int i) {
    data_type val = vector_get(v, i);

    int j;
    for (j = (i+1); j < vector_size(v); j++)
        vector_set(v, (j-1), vector_get(v, j));

    _vector_deincrement_size(v, 1);
    return val;
}

data_type vector_pop_front(Vector *v) {
    return vector_remove(v, 0);
}

data_type vector_pop_back(Vector *v) {
    return vector_remove(v, (vector_size(v) - 1));
}

void vector_insert(Vector *v, int i, data_type val) {
    int j;
    data_type item;
    
    vector_push_back(v, val);
    for (j = (vector_size(v)-1); j > i; j--) {
        item = vector_get(v, (j-1));
        vector_set(v, (j-1), vector_get(v, j));
        vector_set(v, j, item);
    }

    return;     
}

void vector_swap(Vector *v, int i, int j) {
    data_type val;

    val = vector_get(v, i);
    vector_set(v, i, vector_get(v, j));
    vector_set(v, j, val);
    return;
}

void vector_sort(Vector *v) {
    int i, numSorted = 0, sorted = 0;

    do {
        sorted = 0;
        for (i = 0; i < (vector_size(v) - numSorted - 1); i++) {
            if (i == (vector_size(v) - 1))
                continue;
            if (vector_get(v, i) > vector_get(v, (i+1))) {
                vector_swap(v, i, (i+1));
                sorted = 1;
            }
        }
        numSorted++;
    } while (sorted);

    return;
}

int vector_binary_search(Vector *v, data_type val) {
    int min = 0;
    int max = vector_size(v) - 1;
    int central;
    data_type item;

    while (min <= max) {
        central = min + ((max - min) / 2);
        item = vector_get(v, central);
        if (item == val) {
            return central;
        } else if (val > item) {
            min = central + 1;
        } else {
            max = central - 1;
        }
    }

    return -1;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

// internas:

void _vector_validate_index(Vector *v, int i) {
    if (i < 0 || i >= v->size) {
        printf("Indice invalido\n");
        exit(0);
    }
    return;
}

void _vector_deincrement_size(Vector *v, int i) {
    if (vector_size(v) - i < 0) {
        printf("Error: _vector_deincrement: vector size smaller than passed argument.\n");
        exit(0);
    }
    v->size--;
    return;
}