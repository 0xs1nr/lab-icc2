#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertion_sort(int *v, int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i;
		while(v[j] < v[j-1] && j != 0)
		{
			swap(&v[j], &v[j-1]);
     			j--;
		}
	}
}

int main()
{
	int N, J;
	scanf("%d %d", &N, &J);

	int pesos[N];
	for(int i = 0; i < N; i++) scanf("%d", &pesos[i]);

	/* Método de ordenação: 
	 * Como que o número de elementos do vetor que estão desordenados é constante,
	 * o Insertion Sort é capaz de realizar a ordenação em O(N). */
	insertion_sort(pesos, N);

	/* Método de agrupamento:
	 * Tentamos agrupar a pessoa mais pesada com a mais leve.
	 * se exceder o limite do barco, colocamos no barco somente
	 * a pessoa mais pesada. */

	int i = 0; // Pessoa mais leve
	int j = N - 1; // Pessoa mais pesada
	int barcos = 0;
	while(i <= j)
	{
		if(pesos[i] + pesos[j] <= J)
		{
			i++; // Agrupamos com a pessoa mais leve
		}

		j--;

		barcos++;
	}

	printf("%d\n", barcos);

	return 0;
}
