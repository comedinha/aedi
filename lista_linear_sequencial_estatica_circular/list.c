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
	int x = -1;
	l->count--;
	if (!last) {
        x = l->items[l->first];
		if (l->last < l->first) {
			if (l->first == l->max) {
				l->first = 0;
			} else {
				l->first--;
			}
		} else {
			l->first++;
		}
	} else {
	    x = l->items[l->last];
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
    int i;
	if (l->first > l->last) {
		for (i = l->first; i < l->max; i++) {
			printf("Item[%d] = %d\n", i, l->items[i]);
		}
		for (i = 0; i < l->last + 1; i++) {
			printf("Item[%d] = %d\n", i, l->items[i]);
		}
	} else {
		for (i = l->first; i < l->last + 1; i++) {
			printf("Item[%d] = %d\n", i, l->items[i]);
		}
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

//Insere o elemento x na posição i
void insert_at_value(int x, int i, list *l)
{
    int k, j;
	if (is_null(l) || is_full(l)) return;
	if (l->first > l->last) {
	    if ((i < l->first || i > l->max) && (i < 0 || i > l->last)) return; //Testar
	} else {
        if (i < 0 || i > l->last) return;
	}
	if (is_empty(l)) {
		l->items[0] = x;
		l->first = 0;
		l->last = 0;
		l->count = 1;
		return;
	}

	if (i == l->last) {
		l->last++;
		l->items[l->last] = x;
	} else {
	    int j;
		if (l->last > l->first) {
		    if (i < l->first) {
                printf("GO\n");
                for (k = l->last; k >= 0; k--) {
                    l->items[k + 1] = l->items[k];
                }
                l->items[0] = l->items[l->max];
                for (j = l->max - 1; j >= i; j--) {
                    l->items[j + 1] = l->items[j];
                }
            } else {
                for (j = l->last; j >= i; j--) {
                    l->items[j + 1] = l->items[j];
                }
            }
		} else {
		    for (j = l->last; j >= i; j--) {
                l->items[j + 1] = l->items[j];
            }
		}
		l->last++;
        l->items[i] = x;
	}
	l->count++;
}

//Insere o elemento x na primeira ou última posição
bool insert_at(int x, bool last, list *l)
{
    if (is_null(l) || is_full(l)) return false;
	if (is_empty(l)) {
		l->first = 0;
		l->last = 0;
		l->count = 1;
		l->items[l->first] = x;
		return true;
	}

	l->count++;
	if (last) {
		l->last++;
		l->items[l->last] = x;
	} else {
	    if (l->first == 0) {
            l->first = l->max - 1;
            l->items[l->first] = x;
            return true;
        }
        l->first--;
		l->items[l->first] = x;
	}
	return true;
}

//Insere um elemento na primeira posição
bool insert_first(int x, list *l)
{
    if (is_null(l))
        return false;
    return insert_at(x, false, l);
}

//Insere um elemento na última posição
bool insert_last(int x, list *l)
{
    if (is_null(l))
        return false;
    return insert_at(x, true, l);
}

//Procura por um elemento e retorna sua posição
int search(int x, list *l)
{
    int i;
    if (is_null(l) || is_empty(l))
        return -1;
    for (i = l->first; i < l->last; i++)
    {
        if (x == l->items[i])
            return i;
    }
    return -1;
}
