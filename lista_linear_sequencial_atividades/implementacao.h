#include <stdbool.h>
#include "list.h"

#ifndef IMPLEMENTACAO_H
#define IMPLEMENTACAO_H

int remove_insert(int x, int y, list *l);
bool checkExist(int x, list *l);
bool addExist(int x, int i, list *l);
void ordenarValores(list *l);
bool concatenarListas(list *x, list *y, list *z);
bool verificarOrdenacao(list *l);
void inverterElementos(list *l);
void inserePilha(list *l, list *x);
bool inserePilhaVerifica(list *m, list *l, list *x);

#endif
