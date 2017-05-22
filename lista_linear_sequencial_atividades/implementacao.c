#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "list.h"
#include "pilha.h"

//Exercício 1
int remove_insert(int i, int k, list *l)
{
    int x;
	x = remove_at_pos(i, l);
	insert_at_pos(x, k, l);
	return x;
}

//Exercício 2
bool checkExist(int x, list *l)
{
    int i;
    for (i = 0; i < l->max; i++) {
        if (l->items[i] == x) {
            return true;
        }
    }
    return false;
}

bool addExist(int x, int i, list *l)
{
    if (checkExist(x, l)) {
        return false;
    }

    return insert_at_pos(x, i, l);
}

//Exercicio 3
void ordenarValores(list *l)
{
    int i, j, aux;
    l->first = 0;
    l->last = l->count - 1;
    for (i = 0; i < l->max - 1; i++) {
        for (j = 0; j < l->max - i - 1; j++) {
            if (l->items[j] > l->items[j + 1])
            {
                aux = l->items[j];
                l->items[j] = l->items[j + 1];
                l->items[j + 1] = aux;
            }
        }
    }
}

//Exercicio 4
bool concatenarListas(list *x, list *y, list *z)
{
    int i;
    for (i = 0; i < y->max; i++) {
        insert_last(y->items[i], x);
    }
    for (i = 0; i < z->max; i++) {
        insert_last(z->items[i], x);
    }
    return true;
}

//Exercicio 5
bool verificarOrdenacao(list *l)
{
    int i, j;
    for (i = 0; i < l->max - 1; i++) {
        for (j = 0; j < l->max - i - 1; j++) {
            if (l->items[j] > l->items[j + 1])
            {
                return false;
            }
        }
    }
    return true;
}

//Exercicio 6
void inverterElementos(list *l)
{
    int i;
    for (i = 0; i < count_fila(l); i++) {
        enqueue(pop(l), l);
    }
}

//Exercicio 7: Não há diferença, pois ambos são first-in, enquanto na lista não há ordem de retirada.

//Exercicio 8
void inserePilha(list *l, list *x)
{
    if (max_pilha(l) > count_pilha(l) + count_pilha(x)) {
        return;
    }

    int i;
    for (i = 0; i < count_pilha(x); i++) {
        push(pop(x), l);
    }
}

//Exercicio 9
bool inserePilhaVerifica(list *m, list *l, list *x)
{
    if (max_pilha(m) > count_pilha(l) + count_pilha(x)) {
        return;
    }

    int i, y, z;
    for (i = 0; i < max_pilha(m); i++) {
        y = pop(l);
        z = pop(x);
        if (x == -1 || y == -1) {
            printf("Falso\n");
        } else {
            if (y == z) {
                printf("Verdadeiro\n");
            } else {
                printf("Falso\n");
            }
        }
        push(y, m);
        push(z, m);
    }
}
