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

int main()
{
    sparse_matrix *a = new_sparce_matrix(10, 10);

    set_value(8, 5, -1, a);
    set_value(4, -1, 3, a);
    set_value(15, 5, 3, a);

    print_sparse_matrix(a);

    printf("%d\n", get_value(5, 3, a));
    printf("%d\n", get_value(-1, 4, a));
    printf("%d\n", get_value(-1, 3, a));
    printf("%d\n", get_value(5, -1, a));

    clear_sparce_matrix(a);
    print_sparse_matrix(a);

    destroy_sparse_matrix(&a);
    printf("Lista destruida e sem dangling pointers? %s\n", a == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
    return EXIT_SUCCESS;
}
