#include <stdbool.h>
#include "list.h"

#ifndef FILA_H
#define FILA_H

bool enqueue(int x, list *l);
bool dequeue(list *l);
int peek_fila(list *l);
int count_fila(list *l);
int max_fila(list *l);

#endif
