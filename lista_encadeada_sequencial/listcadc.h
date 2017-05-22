#ifndef LISTCADC_H
#define LISTCADC_H

typedef struct Node {
	int x;
	struct Node *next;
} node;

typedef struct {
	node *last;
	int count;
	int max;
} linked_list;

linked_list *new_linked_list(int size);
int is_empty(linked_list *l);
int is_full(linked_list *l);
void insert_first(int x, linked_list *l);
node *create_node(int x);
void print(linked_list *l);
int remove_first(linked_list *l);
int remove_last(linked_list *l);
void insert_last(int x, linked_list *l);
void insert_at(int x, int pos, linked_list *l);
int remove_at(int pos, linked_list *l);
void search(int x, linked_list *l);

#endif
