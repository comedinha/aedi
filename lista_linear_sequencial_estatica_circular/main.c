#include <stdlib.h>
#include <stdio.h>
#include "list.h"

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
    printf("Inserido 20 na segunda posicao\n");
    insert_at_pos(20, 2, l);
    print(l);
    printf("Inserido 30 na nona posicao\n");
    insert_at_pos(30, 9, l);
    print(l);
    printf("Item %d removido da primeira posicao.\n", remove_at_pos(0, l));
    print(l);
    printf("Item %d removido da ultima posicao.\n", remove_at_pos(9, l));
    print(l);
    printf("Item %d removido da oitava posicao.\n", remove_at_pos(8, l));
    print(l);
    destroy_list(&l);
    printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}