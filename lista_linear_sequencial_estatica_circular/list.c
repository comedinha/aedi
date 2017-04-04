#include <stdlib.h>
#include <stdio.h>
#include "list.h"

list *new_list(int size)
{
    list *l = (list *)malloc(sizeof(list));
    l->items = (int *)malloc(size * sizeof(int));
    l->count = 0;
    l->first = -1;
    l->last = -1;
    l->max = size;
    return l;
}

int is_null(list *l)
{
    return l == NULL;
}

void clear(list *l)
{
    if (is_null(l))
        return;
    l->count = 0;
    l->first = -1;
    l->last = -1;
}

int remove_at(bool last, list *l)
{
	if (is_null(l) || is_empty(l)) return -1;
	l->count--;
	if (!last) {
		if (l->last > l->first) {
			if (l->first == l->max) {
				l->first = 0;
			} else {
				l->first++;
			}
		} else {
			l->first--;
		}
	} else {
		l->last--;
	}
	if (is_empty(l))
	{
		l->first = -1;
	}
	return x;
}

int is_empty(list *l)
{
    return is_null(l) || l->count == 0;
}

int is_full(list *l)
{
    return l->count == l->max;
}

void print(list *l)
{
    for (int i = 0; i < l->count; i++)
    {
        printf("Item[%d] = %d\n", i, l->items[i]);
    }
}

void destroy_list(list **l)
{
    free((*l)->items);
    free(*l);
    *l = NULL;
}

//Remove o último elemento e o retorna
int remove_last(list *l)
{
    if (is_null(l))
        return -1;
    return remove_at(true, l);
}

//Remove o primeiro elemento e o retorna
int remove_first(list *l)
{
    if (is_null(l))
        return -1;
    return remove_at(false, l);
}

//Insere o elemento x na primeira ou última posição
void insert_at(int x, bool last, list *l)
{
    if (is_null(l) || is_full(l)) return;
	l->count++;
	if (is_empty(l)) {
		l->first = 0;
		l->last = 0;
		l->items[l->first] = x;
	} else {
		if (last) {
			l->last++;
			l->items[l->last] = x;
		} else {
			if (l->last > l->first) {
				l->first--;
				l->items[l->first] = x;
			} else {
				l->first = l->max;
				l->items[l->max] = x;
			}
		}
	}
}

//Insere um elemento na primeira posição
void insert_first(int x, list *l)
{
    if (is_null(l))
        return;
    insert_at(x, false, l);
}

//Insere um elemento na última posição
void insert_last(int x, list *l)
{
    if (is_null(l))
        return;
    insert_at(x, true, l);
}

//Procura por um elemento e retorna sua posição
int search(int x, list *l)
{
    if (is_null(l) || is_empty(l))
        return -1;
    for (int i = l->first; i < l->last; i++)
    {
        if (x == l->items[i])
            return i;
    }
    return -1;
}