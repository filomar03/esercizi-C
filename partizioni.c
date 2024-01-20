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

#define N 8

int leggiArray(const char * nomeFile, int * destinazione) {
    FILE * stream = fopen(nomeFile, "r");

    int i = 0;
    while (!feof(stream) && i < N) {
        int n;
        fscanf(stream, "%d ", &n);
        destinazione[i] = n;
        i++;
    }

    return i;

    fclose(stream);
}


int main(int argc, const char * argv[]) {
    int a[N];

    int numeri = leggiArray(argv[1], a);

    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }

    Lista lista = NULL;

    stampa(partiziona(a, numeri, atoi(argv[2]), &lista));
}