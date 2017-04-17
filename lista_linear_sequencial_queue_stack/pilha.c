#include <stdlib.h>
#include <stdio.h>
#include "list.h"

bool push(int x, list *l)
{
	return insert_last(x, l);
}

int pop(list *l)
{
	return remove_last(l);
}

int peek_pilha(list *l)
{
	return l->items[l->last];
}

int count_pilha(list *l)
{
	return l->count;
}

int max_pilha(list *l)
{
	return l->max;
}
