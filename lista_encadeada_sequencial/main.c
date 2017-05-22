#include <stdio.h>
#include <stdlib.h>
#include "listcadd.h"

void main(){
	linked_list *l = new_linked_list(10);

	insert_first(10, l);
	insert_first(20, l);
	insert_first(30, l);
	insert_first(40, l);
	printf("Adicionados 40, 30, 20, 10.\n");
	print(l);
	insert_last(80, l);
	insert_last(5, l);
	insert_last(44, l);
	printf("Adicionados 80, 5, 44.\n");
	print(l);
	insert_at(31, 5, l);
	printf("31 adicionado na 5 posicao.\n");
	print(l);
	remove_first(l);
	printf("primeiro valor removido\n");
	print(l);
	remove_last(l);
	printf("ultimo valor removido\n");
	print(l);
	remove_at(5, l);
	printf("valor da 5 posisao removido\n");
	print(l);
	search(30, l);
	search(50, l);
}
