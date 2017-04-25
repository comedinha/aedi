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
	    if (l->last == 0) {
            l->last = l->max - 1;
	    } else {
            l->last--;
	    }
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
		for (i = 0; i <= l->last; i++) {
			printf("Item[%d] = %d\n", i, l->items[i]);
		}
	} else {
		for (i = l->first; i <= l->last; i++) {
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

//Remove o elemento na posição i
int remove_at_pos(int i, list *l)
{
    int j, k, y;
	if (is_null(l) || is_empty(l)) return -1;
	if (l->first > l->last) {
	    if ((i < l->first || i > l->max - 1) && (i < 0 || i > l->last)) return -1;
    } else {
        if (i < 0 || i > l->last) return -1;
	}
	int x = l->items[i];
	if ((l->first > l->last) && (i > l->last)) {
        y = l->items[0];
        for (j = 0; j < l->last; j++)
        {
            l->items[j] = l->items[j + 1];
        }
        for (k = i; k < l->max - 1; k++)
        {
            l->items[k] = l->items[k + 1];
        }
        l->items[l->max - 1] = y;
    } else {
        for (j = i; j < l->last; j++)
        {
            l->items[j] = l->items[j + 1];
        }
    }
	l->count--;
	l->last--;
	if (is_empty(l))
	{
		l->first = -1;
	}
	return x;
}

//Insere o elemento x na posição i
bool insert_at_pos(int x, int i, list *l)
{
    int k, j;
    if (is_null(l) || is_full(l)) return false;
    if (l->first > l->last) {
        if ((i < l->first || i > l->max - 1) && (i < 0 || i > l->last)) return false;
    } else {
        if (i < 0 || i > l->last) return false;
    }
    if (is_empty(l)) {
        l->items[0] = x;
        l->first = 0;
        l->last = 0;
        l->count = 1;
        return true;
    }

    if (i == l->last) {
        if (l->last == l->max - 1) {
            l->last = 0;
        } else {
            l->last++;
        }
        l->items[l->last] = x;
    } else {
        if ((l->first > l->last) && (i > l->last)) {
            for (j = l->last; j >= 0; j--) {
                l->items[j + 1] = l->items[j];
            }
            l->items[0] = l->items[l->max - 1];
            for (k = l->first; k >= i; k--) {
                l->items[k + 1] = l->items[k];
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
    return true;
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
        if (l->last == l->max - 1) {
            l->last = 0;
        } else {
            l->last++;
        }
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
