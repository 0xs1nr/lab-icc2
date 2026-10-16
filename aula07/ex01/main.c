#include <stdio.h>

#define output(v, n) for(int i = 0; i < n; i++) i != n-1 ? printf("%d ", v[i]) : printf("%d\n", v[i]);

void merge(int *v, int left, int mid, int right)
{
	/* Armazena os dois vetores a serem intercalados
	 * em arrays temoporários */	

	// Tamanho dos arrays
	int N1 = mid - left + 1;
	int N2 = right - mid;

	// Array da esquerda
	int L[N1];
	for(int i = 0; i < N1; i++)
		L[i] = v[left + i];

	// Array da direita
	int R[N2];
	for(int j = 0; j < N2; j++)
		R[j] = v[mid + 1 + j];
	
	/* Intercala dos dois arrays temporários
	 * no vetor principal */

	// Ponteiros para os elementos dos arrays
	int Lptr = 0;
	int Rptr = 0;
	int k = left; // Ponteiro para os elementos do vetor principal

	// Percorre cada um dos arrays comparando seus elementos
	// Até que um deles acabe
	while(Lptr < N1 && Rptr < N2)
	{
		if(L[Lptr] <= R[Rptr])
		{
			v[k] = L[Lptr];
			Lptr++;
		}
		else
		{
			v[k] = R[Rptr];
			Rptr++;
		}
		k++;
	}

	// Copia o restante dos elementos de L para o vetor principal (se há algum)
	while(Lptr < N1)
	{
		v[k] = L[Lptr];
		Lptr++;
		k++;
	}
	
	// Copia o restante dos elementos de R para o vetor principal (se há algum)
	while(Rptr < N2)
	{
		v[k] = R[Rptr];
		Rptr++;
		k++;
	}
}	

void merge_sort(int *v, int left, int right)
{
	// Etapa de divisão
	if(left >= right)
		return;

	int mid = left + (right-left) / 2;

	merge_sort(v, left, mid); // Divide à esquerda

	merge_sort(v, mid + 1, right); // Divide à direita
	
	// Etapa de conquista (intercalação)
	merge(v, left, mid, right);
}

int main()
{
	int N;
	scanf("%d", &N);

	int v[N];
	for(int i = 0; i < N; i++) scanf("%d", &v[i]);

	merge_sort(v, 0, N-1);

	for(int i = 1; i < N; i++)
	{
		if(v[i] == v[i-1])
		{
			printf("%d\n", v[i]);
			break;
		}
	}
	
	return 0;
}
