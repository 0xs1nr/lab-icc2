#include <stdio.h>
#include <string.h>

#define output(v, n) for(int i = 0; i < n; i++) i != n-1 ? printf("%d ", v[i]) : printf("%d\n", v[i]);

struct triple {
	int F;
	float T;
	float P;
};

void swap(int *a, int *b);
void bubble_sort(int *v, int n);
void insertion_sort(int *v, int n);
int partition(int *v, int left, int right);
void quick_sort(int *v, int left, int right);
void merge(int *v, int left, int mid, int right);
void merge_sort(int *v, int left, int right);

int main()
{
	int N;
	scanf("%d", &N);



	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int *v, int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j < n-i; j++)
		{
			if(v[j] < v[j-1])
				swap(&v[j], &v[j-1]);
		}
	}
}

void insertion_sort(int *v, int n)
{
	for(int i = 1; i < n; i++)
	{
		int j = i;
		while(v[j] < v[j-1] && j > 0)
		{
			swap(&v[j], &v[j-1]);
		}
	}
}

int partition(int *v, int left, int right)
{
	int pivot = (right+left) / 2;
	
	/* Etapa de divisão
	 * Fazemos o pivot possuir as seguintes propriedades:
	 * 1. Estar na sua posição ordenada correta
	 * 2. Todos os elementos anteriores ao pivot são menores
	 * 3. Todos os elementos sucessores ao pivot são maiores */

	swap(&v[pivot], &v[right]); // Troca o pivot de lugar com o ultimo elemento
	
	int x = v[right]; // Pivot

	int i = left - 1;

	for(int j = left; j <= right-1; j++)
	{
		if(v[j] <= x)
		{
			i++;
			swap(&v[i], &v[j]);
		}
	}

	swap(&v[i+1], &v[right]);

	return i + 1;
}

void quick_sort(int *v, int left, int right)
{
	if(left >= right)
		return;

	int pivot = partition(v, left, right);

	quick_sort(v, left, pivot - 1);

	quick_sort(v, pivot + 1, right);
}

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

