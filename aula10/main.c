#include <stdio.h>
#include "linked_list.h"

int insert(LinkedList *hash_table[], int M, int x);
int search(LinkedList *hash_table[], int M, int x);

int main()
{
	int M, Q;
	scanf("%d %d", &M, &Q);

	LinkedList *hash_table[M];
	for(int i = 0; i < M; i++)
		hash_table[i] = create_linked_list();

	while(Q--)
	{
		char op;
		int x;

		scanf(" %c %d", &op, &x);

		if(op == 'I')
		{
			int pos = insert(hash_table, M, x);

			printf("%d\n", pos);
		}
		else if(op == 'B')
		{
			if(search(hash_table, M, x))
				puts("SIM");
			else
				puts("NAO");
		}
	}

	for(int i = 0; i < M; i++)
		free_linked_list(&hash_table[i]);

	return 0;
}

int h(int x, int M)
{
	return x % M;
}

int insert(LinkedList *hash_table[], int M, int x)
{
	insert_node(hash_table[h(x, M)], 0, x);

	return h(x, M);
}

int search(LinkedList *hash_table[], int M, int x)
{
	if(search_node(hash_table[h(x, M)], x))
		return 1;

	return 0;
}
