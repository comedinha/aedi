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

int remove_at(int i, list *l)
{
    if (is_null(l) ||
        is_empty(l) ||
        (i < 0 || i > l->last))
        return -1;
    int x = l->items[i];
    for (int j = i; j < l->last; j++)
    {
        l->items[j] = l->items[j + 1];
    }
    l->last--;
    l->count--;
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
    return remove_at(l->last, l);
}

//Remove o primeiro elemento e o retorna
int remove_first(list *l)
{
    if (is_null(l))
        return -1;
    return remove_at(l->first, l);
}

//Insere o elemento x na posição i
void insert(int x, list *l)
{
    if (is_null(l) || is_full(l)) return;
	l->count++;
	if (l->items[l->last] > x) {
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