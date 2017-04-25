#include <stdlib.h>
#include <stdio.h>
#include "fila.h"
#include "pilha.h"

void main() {
    printf("Fila:\n");
    list *f = new_list(10);
    enqueue(0, f);
    enqueue(10, f);
    enqueue(20, f);
    enqueue(30, f);
    enqueue(40, f);
    enqueue(50, f);
    printf("Inserido: 0, 10, 20, 30, 40, 50\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    enqueue(40, f);
    printf("Inserido: 40\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    enqueue(120, f);
    printf("Inserido: 120\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    printf("Removido: %d\n", dequeue(f));
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    printf("Removido: %d\n", dequeue(f));
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    enqueue(1, f);
    printf("Inserido: 1\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    enqueue(2, f);
    printf("Inserido: 2\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    enqueue(3, f);
    printf("Inserido: 3\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    enqueue(4, f);
    printf("Inserido: 4\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_fila(f), count_fila(f), max_fila(f));
    destroy_list(&f);
    printf("Lista destruida e sem dangling pointers? %s\n\n\n", f == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");

    printf("Pilha:\n");
    list *p = new_list(10);
    push(0, p);
    push(10, p);
    push(20, p);
    push(30, p);
    push(40, p);
    push(50, p);
    printf("Inserido: 0, 10, 20, 30, 40, 50\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_pilha(p), count_pilha(p), max_pilha(p));
    push(40, p);
    printf("Inserido: 40\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_pilha(p), count_pilha(p), max_pilha(p));
    push(120, p);
    printf("Inserido: 120\n");
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_pilha(p), count_pilha(p), max_pilha(p));
    printf("Removido: %d\n", pop(p));
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_pilha(p), count_pilha(p), max_pilha(p));
    printf("Removido: %d\n", pop(p));
    printf("Primeiro elemento: %d\nQuantidade de itens: %d\nTamanho maximo:%d\n\n", peek_pilha(p), count_pilha(p), max_pilha(p));
    destroy_list(&p);
    printf("Lista destruida e sem dangling pointers? %s\n\n\n", p == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}
