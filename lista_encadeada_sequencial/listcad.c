#include <stdlib.h>
#include <stdio.h>
#include "listcad.h"

linked_list *new_linked_list(int size) {
	linked_list *l = (linked_list*) malloc(sizeof(linked_list));
	l->count = 0;
	l->max = size;
	l->first = NULL;
	return l;
}

node *create_node(int x) {
	node *new_node = (node*) malloc(sizeof(node));
	new_node->x = x;
	new_node->next = NULL;
	return new_node;
}

int is_empty(linked_list *l) {
	return l == NULL || l->first == NULL;
}

int is_full(linked_list *l) {
	return l == NULL || l->max == -1 ? 0 : l->count == l->max;
}

void print(linked_list *l) {
	if (is_empty(l)) return;

	node *aux = l->first;
	while(aux != NULL) {
		printf("%d\n", aux->x);
		aux=aux->next;
	}
}

void insert_first(int x, linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	if(is_empty(l)){
		l->first = new_node;
	}else{
		new_node->next = l->first;
		l->first = new_node;
	}
	l->count++;
}

void insert_last(int x, linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	node *aux = l->first;
	if(is_empty(l)){
		l->first = new_node;
	}else{
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = new_node;
		new_node->next = NULL;
	}
	l->count++;
}

void insert_at(int x, int pos, linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	node *aux = l->first;
	int i;

	if(is_empty(l) || pos == 0){
		l->first = new_node;
	}else{
		for(i = 0; i < pos-1; ++i){
			aux=aux->next;
		}
		node *aux2 = aux->next;
		aux->next = new_node;
		new_node->next = aux2;
		l->count++;
	}
}

int remove_first(linked_list *l) {
	if(l == NULL) return -1;

	node *aux = l->first;
	int x = l->first->x;
	l->first = aux->next;
	aux->next = NULL;
	l->count--;
	return x;
}

int remove_last(linked_list *l) {
	if (is_empty(l)) return -1;

	node *aux = l->first;
	while(aux->next->next != NULL){
		aux = aux->next;
	}
	int x = aux->next->x;
	free(aux->next);
	aux->next = NULL;
	l->count--;
	return x;
}

int remove_at(int pos, linked_list *l) {
	int i;
	if(l == NULL || is_full(l) || is_empty(l)) return -1;

	if (pos == 0){
		return remove_first(l);
	}else{
	    node *aux = l->first;
		for(i = 0; i < pos-1; ++i){
			aux = aux->next;
		}
		int x = aux->next->x;
		node *aux2 = aux->next->next;
		free(aux->next);
		aux->next = NULL;
		aux->next = aux2;
		l->count--;
		return x;
	}
}

void search(int x, linked_list *l) {
	if (is_empty(l)) return;

	node *aux = l->first;
	int cont = 0;
	while (aux != NULL){
		if (x == aux->x){
			printf("Elemento encontrado na posicao %d\n", cont);
			return;
		}
		cont++;
		aux=aux->next;
	}
	printf("Elemento nao encontrado!\n");
	return;
}

void destroy_linked_list(linked_list **l) {
	if (is_empty(*l)) return;

	node *aux = (*l)->first;
	while(aux != NULL) {
		node *del = aux;
		aux=aux->next;
		free(del);
	}
	free(*l);
	*l = NULL;
}
