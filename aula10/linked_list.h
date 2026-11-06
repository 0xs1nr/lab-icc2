#ifndef LINKED_LISTH
#define LINKED_LISTH

typedef struct linked_list LinkedList;

LinkedList *create_linked_list(void);
int insert_node(LinkedList *l, int pos, int value);
int search_node(LinkedList *l, int x);
void free_linked_list(LinkedList **l);

#endif
