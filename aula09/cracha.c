#include <stdio.h>

int h(int x, int M);
int insert(int *hash_table, int M, int x);
int search(int *hash_table, int M, int x);

int main()
{
	int M;
	int Q;
	
	scanf("%d %d", &M, &Q);
	
	// Cria uma tabela hash vazia
	int hash_table[M];

	for(int i = 0; i < M; i++)
		hash_table[i] = -1; // -1 indica vazio

	while(Q--)
	{
		char operation;
		int x;

		scanf(" %c", &operation);
		scanf(" %d", &x);

		if(operation == 'I')
		{
			int pos = insert(hash_table, M, x);

			printf("%d\n", pos);
		}
		else if(operation == 'B')
		{
			if(search(hash_table, M, x))
			{
				puts("SIM");
			}
			else
			{
				puts("NAO");
			}
		}
	}

	return 0;
}

int h(int x, int M)
{
	return x % M;
}

int insert(int *hash_table, int M, int x)
{
	int y = x;
	while(hash_table[h(y, M)] != -1)
	{
		y++;
	}

	hash_table[h(y, M)] = x;

	return h(y, M); // Retorna a posicao em que foi inserido
}

int search(int *hash_table, int M, int x)
{
	int y = x;
	while(hash_table[h(y, M)] != x)
	{
		if(hash_table[h(y, M)] == -1)
		{
			return 0; // Nao encontrou
		}

		y++;
	}

	return 1; // Encontrou
}
