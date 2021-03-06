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

#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct Node
{
    int value, i, j;
    struct Node *right;
    struct Node *down;
} node;

typedef struct
{
    node *first;
    int m;
    int n;
} sparse_matrix;

sparse_matrix *new_sparce_matrix(int m, int n);
void clear_sparce_matrix(sparse_matrix *a);
void destroy_sparse_matrix(sparse_matrix **a);
int get_value(int i, int j, sparse_matrix *a);
void set_value(int v, int i, int j, sparse_matrix *a);
void print_sparse_matrix(sparse_matrix *a);

#endif
