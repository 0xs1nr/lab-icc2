#include <stdio.h>
#include <stdlib.h>

#define output(v, n) for(int i = 0; i < n; i++) i != n - 1 ? printf("%c ", v[i]) :  printf("%c\n", v[i]); // Debug

char h(char x, int M);
int insert(char *hash_table, int M, char x);
int search(char *hash_table, int M, char x);

int main()
{
	int M = 100000;

	char *A = malloc(sizeof(char) * M);
	if(!A)
		return -1;
	
	scanf("%s", A);

	char *B = malloc(sizeof(char) * M);
	if(!B)
		return -1;
	
	scanf("%s", B);
	
	// Cria uma tabela hash vazia
	char hash_table[M];
	for(int i = 0; i < M; i++)
		hash_table[i] = '0';

	// Insere os elementos da primeira string na tabela hash [O(N)]
	for(; *A != '\0'; A++)
		insert(hash_table, M, *A);

	// Busca os elementos da segunda string na tabela hash, [O(M)]
	// removendo os elementos encontrados
	for(; *B != '\0'; B++)	
		// Se o elemento nao existe, e impossivel formar a palavra
		if(search(hash_table, M, *B) == 0)
		{	
			printf("NAO\n");
			return 0;
		}

	// Se todas os caracteres foram encontrados, e possivel formar a palavra
	printf("SIM\n");

	return 0;
}

char h(char x, int M)
{
	return (int) x % M;
}

int insert(char *hash_table, int M, char x)
{
	char y = x;
	while(hash_table[h(y, M)] != '0')
	{
		y++;
	}

	hash_table[h(y, M)] = x;

	return h(y, M); // Retorna a posicao em que foi inserido
}

int search(char *hash_table, int M, char x)
{
	char y = x;
	while(hash_table[h(y, M)] != x)
	{
		if(hash_table[h(y, M)] == '0')
		{
			return 0; // Nao encontrou
		}

		y++;
	}

	hash_table[h(y, M)] = '0'; // Remove o caractere da hash table

	return 1; // Encontrou
}
