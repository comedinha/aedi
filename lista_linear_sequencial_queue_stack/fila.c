#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool enqueue(int x, list *l)
{
	return insert_last(x, l);
}

int dequeue(list *l)
{
	return remove_first(l);
}

int peek_fila(list *l)
{
	return l->items[l->first];
}

int count_fila(list *l)
{
	return l->count;
}

int max_fila(list *l)
{
	return l->max;
}
