#include <stdio.h>
#include <stdlib.h>

#define output(v, n) for(int i = 0; i < n; i++) i != n-1 ? printf("%d ", v[i]) : printf("%d\n", v[i]);

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int *vector, int N) 
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(vector[j] < vector[j-1])
				swap(&vector[j], &vector[j-1]);
		}
	}
}

int main()
{
	int N;
	int J;
	scanf("%d %d", &N, &J);

	int pessoas[N];
	for(int i = 0; i < N; i++) scanf("%d", &pessoas[i]);

	output(pessoas, N);

	bubble_sort(pessoas, N);

	output(pessoas, N);

	return 0;
}
