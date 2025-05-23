#include <stdbool.h>

typedef struct UF {
    int *array;
    int capacity;
} UF;

// Inicializa estrutura com N objetos numerados de 0 a N-1.
UF *UF_init(int N);
// Adiciona uma conexao entre p e q.
void UF_union(UF *uf, int p, int q);
// Retorna o identificador do componente de p (entre 0 a N-1).
int UF_find(UF *uf, int p);
// Os objetos p e q estao no mesmo componente?
bool UF_connected(UF *uf, int p, int q);

void UF_destroy(UF *uf);