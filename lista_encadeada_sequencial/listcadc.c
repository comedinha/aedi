#include <stdlib.h>
#include <stdio.h>
#include "listcadc.h"

linked_list *new_linked_list(int size) {
	linked_list *l = (linked_list*) malloc(sizeof(linked_list));
	l->count = 0;
	l->max = size;
	l->last = NULL;
	return l;
}

node *create_node(int x) {
	node *new_node = (node*) malloc(sizeof(node));
	new_node->x = x;
	new_node->next = NULL;
	return new_node;
}

int is_empty(linked_list *l) {
	return l == NULL || l->last == NULL;
}

int is_full(linked_list *l) {
	return l == NULL || l->max == -1 ? 0 : l->count == l->max;
}

void print(linked_list *l) {
    if (is_empty(l)) return;

    node *aux = l->last->next;
    while (aux != l->last) {
        printf("%d\n", aux->x);
        aux = aux->next;
    }
    printf("%d\n", l->last->x);
}

void insert_first(int x, linked_list *l) {
	if (l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	if (is_empty(l)) {
		l->last = new_node;
		l->last->next = new_node;
	} else {
		node *aux = l->last;
		new_node->next = aux->next;
		aux->next = new_node;
	}
	l->count++;
}

void insert_last(int x, linked_list *l) {
	if (l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	if (is_empty(l)) {
		l->last = new_node;
		l->last->next = new_node;
	} else {
		node *aux = l->last;
		new_node->next = aux->next;
		aux->next = new_node;
	}
	l->count++;
}

void insert_at(int x, int pos, linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	int i;

	if (is_empty(l)) {
		l->last = new_node;
		l->last->next = new_node;
	} else {
	    node *aux = l->last;
	    node *aux_prev = aux->next;
		for (i = 0; i < pos - 1; i++) {
			aux_prev = aux_prev->next;
		}
		new_node->next = aux_prev->next;
		aux_prev->next = new_node;
		l->count++;
	}
}

int remove_first(linked_list *l) {
	if (l == NULL) return -1;

	node *aux = l->last;
	int x = aux->next->x;
	aux->next = aux->next->next;
	l->count--;
	return x;
}

int remove_last(linked_list *l){
	if (is_empty(l)) return -1;

	node *aux = l->last;
    node *aux_prev = aux;
    while (aux_prev->next != l->last){
        aux_prev = aux_prev->next;
    }
    int x = aux_prev->next->x;
    aux_prev->next = aux->next;
	free(aux);
    l->last = aux_prev;
	l->count--;
	return x;
}

int remove_at(int pos, linked_list *l){
	int i;
	if (l == NULL || is_full(l) || is_empty(l)) return -1;

	if (pos == 0) {
		return remove_last(l);
	} else {
		node *aux = l->last;
	    node *aux_prev = aux->next;
		for (i = 0; i < pos - 1; i++) {
			aux_prev = aux_prev->next;
		}
		node *aux_free = aux_prev->next;
		if (aux_free == aux) {
            l->last = aux_prev;
		}
		int x = aux_prev->next->x;
		aux_prev->next = aux_prev->next->next;
		free(aux_free);
		l->count--;
		return x;
	}
}

void search(int x, linked_list *l){
	if (is_empty(l)) return;

	node *aux = l->last->next;
	int cont = 0;
	while (aux != l->last) {
		if (x == aux->x){
			printf("Elemento encontrado na posicao %d\n", cont);
			return;
		}
		cont++;
		aux = aux->next;
	}
	printf("Elemento nao encontrado!\n");
	return;
}

void destroy_linked_list(linked_list **l) {
	if (is_empty(*l)) return;

	node *aux = (*l)->last;
	while(aux != NULL) {
		node *del = aux;
		aux=aux->next;
		free(del);
	}
	free(*l);
	*l = NULL;
}
