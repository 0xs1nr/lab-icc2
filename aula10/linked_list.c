#include <stdlib.h>
#include "linked_list.h"

#define POINTER_ERROR -1
#define INVALID_POS 0
#define SUCCESS 1

typedef struct node
{
	int data;
	struct node *next;
} Node;

struct linked_list
{
	Node *head;
	int size;
};

LinkedList *create_linked_list(void)
{
	LinkedList *l = malloc(sizeof(LinkedList));
	if(!l)
		return NULL;

	l->head = NULL;
	l->size = 0;

	return l;
}

int insert_node(LinkedList *l, int pos, int value)
{
	if(!l)
		return POINTER_ERROR;

	if(pos < 0 || pos > l->size)
		return INVALID_POS;

	// Cria o novo no
	Node *new = malloc(sizeof(Node));
	if(!new)
		POINTER_ERROR;

	// Coloca o valor no novo no
	new->data = value;
	new->next = NULL;

	// Poe o novo no na posicao correta
	if(pos == 0)
	{
		new->next = l->head;
		l->head = new;
	}
	else
	{
		Node *tmp = l->head;
		for(int i = 0; i < pos-1; i++)
			tmp = tmp->next;

		tmp->next = new;
	}

	l->size++;

	return SUCCESS;
}

int search_node(LinkedList *l, int x)
{
	if(!l)
		return POINTER_ERROR;

	Node *tmp = l->head;
	while(tmp != NULL)
	{
		if(tmp->data == x)
			return 1; // Encontrou

		tmp = tmp->next;
	}

	return 0; // Nao encontrou
}

void free_linked_list(LinkedList **l)
{
	if(!l || !(*l))
		return;

	Node *tmp = (*l)->head;
	while(tmp != NULL)
	{
		Node *rem = tmp;
		tmp = tmp->next;
		free(rem);
	}

	free(*l);
	*l = NULL;
}
