#include <stdio.h>
#include <stdlib.h>

struct node {
    int val1;
    int val2;
    struct node * prox;
};

typedef struct node * Lista;
typedef struct node Elemento;

void aggiungi(Lista * lista, int n1, int n2) {
    if (*lista == NULL) {
        *lista = malloc(sizeof(Elemento));
        (*lista)->val1 = n1;
        (*lista)->val2 = n2;
        (*lista)->prox = NULL;
        return;
    }

    aggiungi(&(*lista)->prox, n1, n2);
}

void stampa(Lista lista) {
    if (lista == NULL) {
        printf("\n");
        return;
    }

    printf("%d:%d ", lista->val1, lista->val2);
    stampa(lista->prox);
}

Lista partiziona(int *a, int n, int y, Lista *lista) {
    int somma = 0;

    int inizio = 0;
    for (int i = 0; i < n; i++) {
        if (somma + a[i] <= y) {
            somma += a[i];
        } else {
            aggiungi(lista, inizio, i - 1);
            inizio = i;
            somma = a[i];
        }

        if (i == n - 1) {
            aggiungi(lista, inizio, i);
        }
        
        /* if (somma == 0) {
            int inizio = i;
            
            for (int j = i; j < n && somma + a[j] <= y; j++) {
                somma += a[j];
                i = j;
            }

            aggiungi(lista, inizio, i);

            somma = 0;
        } */
    }

    return *lista;
}

int main() {
    int a[] = {2, 8, 0, 3, 9, 6, 1, 3};

    Lista lista = NULL;

    stampa(partiziona(a, sizeof(a) / sizeof(a[0]), 10, &lista));
}