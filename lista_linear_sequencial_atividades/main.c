#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "implementacao.h"
#include "fila.h"
#include "pilha.h"

void main() {
    list *l = new_list(10);
    insert_last(0, l);
    insert_last(10, l);
    insert_last(20, l);
    insert_last(30, l);
    insert_last(40, l);
    insert_last(50, l);
    printf("Inserido 0, 10, 20, 30, 40, 50\n");
    print(l);
    printf("Item %d removido da primeira posicao.\n", remove_first(l));
    print(l);
    printf("Item %d removido da primeira posicao.\n", remove_first(l));
    print(l);
    printf("Item %d removido da ultima posicao.\n", remove_last(l));
    print(l);
    printf("Inserido 90 na primeira posicao\n");
    insert_at(90, false, l);
    print(l);
    printf("Inserido 80 na primeira posicao\n");
    insert_first(80, l);
    print(l);
    printf("Inserido 20 na primeira posicao\n");
    insert_at_pos(20, 0, l);
    print(l);
    printf("Inserido 40 na primeira posicao\n");
    insert_first(40, l);
    print(l);
    printf("Inserido 100 na primeira posicao\n");
    insert_first(100, l);
    print(l);
    printf("Item %d removido da primeira posicao.\n", remove_first(l));
    print(l);
    printf("Inserido 100 na primeira posicao\n");
    insert_first(100, l);
    print(l);
    printf("Inserido 20 na segunda posicao\n");
    insert_at_pos(20, 2, l);
    print(l);
    printf("Inserido 30 na nona posicao\n");
    insert_at_pos(30, 9, l);
    print(l);
    printf("Item %d removido da primeira posicao.\n", remove_at_pos(0, l));
    print(l);
    printf("Item %d removido da nona posicao e adicionado na segunda posicao.\n", remove_insert(9, 2, l));
    print(l);
    addExist(20, 1, l) ? printf("adicionado 20 a lista\n") : printf("o numero 20 ja esta na lista (ou ela esta cheia)\n");
    print(l);
    addExist(99, 1, l) ? printf("adicionado 99 a lista\n") : printf("o numero 99 ja esta na lista (ou ela esta cheia)\n");
    print(l);
    addExist(88, 1, l) ? printf("adicionado 88 a lista\n") : printf("o numero 88 ja esta na lista (ou ela esta cheia)\n");
    print(l);
    printf("Verificando ordenacao da lista\n");
    verificarOrdenacao(l) ? printf("lista ordenada\n") : printf("lista nao ordenada\n");
    printf("Ordenando Lista\n");
    ordenarValores(l);
    print(l);
    printf("Verificando ordenacao da lista\n");
    verificarOrdenacao(l) ? printf("lista ordenada\n") : printf("lista nao ordenada\n");
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");

    printf("\n\nListas Novas\n");
    list *m = new_list(3);
    list *n = new_list(3);
    list *o = new_list(m->max + n->max);
    insert_last(0, m);
    insert_last(10, m);
    insert_last(20, m);
    insert_last(30, n);
    insert_last(40, n);
    insert_last(50, n);
    printf("Inserido 0, 10, 20 na lista M\n");
    printf("Inserido 30, 40, 50 na lista N\n");
    printf("Concatenando em O\n");
    concatenarListas(o, m, n);
    print(o);
    destroy_list(&m);
    destroy_list(&n);
    destroy_list(&o);
    printf("Lista destruida e sem dangling pointers? %s\n", m == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
    printf("Lista destruida e sem dangling pointers? %s\n", n == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
    printf("Lista destruida e sem dangling pointers? %s\n", o == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");

    printf("\n\nPilha e Fila\n");
    l = new_list(10);
    enqueue(0, l);
    enqueue(10, l);
    enqueue(20, l);
    enqueue(30, l);
    enqueue(40, l);
    enqueue(50, l);
    printf("Inserido 0, 10, 20, 30, 40, 50\n");
    print(l);
    printf("Invertendo elementos\n");
    inverterElementos(l);
    print(l);
    destroy_list(&l);
    printf("Listas destruidas e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}
