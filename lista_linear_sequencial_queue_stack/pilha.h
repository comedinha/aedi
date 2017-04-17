#include <stdbool.h>
#include "list.h"

#ifndef PILHA_H
#define PILHA_H

bool push(int x, list *l);
bool pop(list *l);
int peek_pilha(list *l);
int count_pilha(list *l);
int max_pilha(list *l);

#endif
