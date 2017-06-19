/*
The MIT License (MIT)
copyright © 2015 <copyright holders>
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the “Software”), to deal in the Software without restriction, including without
limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so, subject to the following
conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions
of the Software.
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT
SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include <stdlib.h>
#include <stdio.h>
#include "matriz_esparsa.h"

sparse_matrix *new_sparce_matrix(int m, int n)
{
    sparse_matrix *a = (sparse_matrix *)malloc(sizeof(sparse_matrix));
    a->m = m;
    a->n = n;
    a->first = (node *)malloc(sizeof(node));
    a->first->value = -1;
    a->first->i = -1;
    a->first->j = -1;
    a->first->right = NULL;
    a->first->down = NULL;
    return a;
}

void clear_sparce_matrix(sparse_matrix *a)
{
    node *first = a->first;
    node *nnode = first;
    node *snode = nnode;
    while (nnode->down != NULL && nnode->right != NULL) {
        snode = nnode;
        if (nnode->down != NULL)
            nnode = nnode->down;
        else
            nnode = nnode->right;

        if (snode != first) {
            free(snode);
            snode = NULL;
        }
    }
    if (nnode != first) {
        free(nnode);
        nnode = NULL;
    }

    a->first->value = -1;
    a->first->i = -1;
    a->first->j = -1;
    a->first->right = NULL;
    a->first->down = NULL;
}

void destroy_sparse_matrix(sparse_matrix **a)
{
    node *first = (*a)->first;
    node *nnode = first;
    node *snode = nnode;
    while (nnode->down != NULL && nnode->right != NULL) {
        snode = nnode;
        if (nnode->down != NULL)
            nnode = nnode->down;
        else
            nnode = nnode->right;
        free(snode);
        snode = NULL;
    }
    free(nnode);
    nnode = NULL;

    free(*a);
    *a = NULL;
}

int get_value(int i, int j, sparse_matrix *a)
{
    if (a == NULL)
        return -1;

    node *nnode = a->first;
    while (nnode->down != NULL || nnode->right != NULL) {
        if (nnode->i == i && nnode->j == j) {
            break;
            return nnode->value;
        }

        if (nnode->down != NULL) {
            nnode = nnode->down;
        } else {
            nnode = nnode->right;
        }
    }

    if (nnode->i == i && nnode->j == j)
        return nnode->value;

    return -1;
}

void set_value(int v, int i, int j, sparse_matrix *a)
{
    node *n = (node *)malloc(sizeof(node));
    n->value = v;
    n->i = i;
    n->j = j;
    n->down = NULL;
    n->right = NULL;

    node *nnode = a->first;
    node *snode = nnode;

    if (nnode->down != NULL && nnode->right != NULL) {
        if (nnode->i == i)
            nnode->down = n;
        else
            nnode->right = n;
        return;
    }
    while (nnode->down != NULL || nnode->right != NULL) {
        snode = nnode;

        if (nnode->down != NULL) {
            nnode = nnode->down;
            if ((snode->i > i && snode->j == j) && (nnode->i < i && nnode->j == j)) {
                snode->down = n;
                n->down = nnode;
                break;
            }
        } else {
            nnode = nnode->right;
            if (snode->i == i) {
                snode->down = n;
                n->right = nnode;
                break;
            } else if (snode->j > j && nnode->j < j) {
                snode->right = n;
                n->right = nnode;
                break;
            } else if (nnode->i > i && nnode->j == j) {
                n->down = nnode->down;
                n->right = nnode->right;
                nnode->down = n;
            } else if (nnode->i < i && nnode->j == j) {
                snode->right = n;
                n->down = nnode;
            }
        }
    }
    if (nnode->j > j)
        nnode->right = n;
    else
        nnode->down = n;
}

void print_sparse_matrix(sparse_matrix *a)
{
    int i, j;

    if (a == NULL)
        return;

    node *first = a->first;
    node *nnode = first;

    for (i = -1; i < a->n; ++i)
    {
        for (j = -1; j < a->m; ++j)
        {
            if (nnode->i == j && nnode->j == i) {
                printf("(%-2d,%2d)=%-5d", j, i, nnode->value);
                if (nnode->down != NULL)
                    nnode = nnode->down;
                else if (nnode->right != NULL)
                    nnode = nnode->right;
            } else
                printf("(%-2d,%2d)=%-5d", j, i, -1);
        }
        printf("\n");
    }
}
