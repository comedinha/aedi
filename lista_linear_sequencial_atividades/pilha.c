#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool push(int x, list *l)
{
	return insert_first(x, l);
}

int pop(list *l)
{
	return remove_first(l);
}

int peek_pilha(list *l)
{
	return l->items[l->first];
}

int count_pilha(list *l)
{
	return l->count;
}

int max_pilha(list *l)
{
	return l->max;
}
