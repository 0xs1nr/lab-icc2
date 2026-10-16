#include <stdio.h>
#include <stdlib.h>

typedef struct {
	long long value;
} Length;

Length read_length()
{
	long long integer; // Parte inteira do número
	int decimal; // Parte decimal

	scanf("%lld.%2d", &integer, &decimal);

	Length l;
	l.value = integer * 100 + decimal;

	return l;
}

void print_length(Length l)
{
	printf("%lld.%02lld\n", l.value / 100, l.value % 100);
}

int main(void)
{
	int N, K;
	scanf("%d %d", &N, &K);

	Length *L = (Length *) malloc(N * sizeof(Length));
	if(!L)
		return 1;

	Length greater;
	greater.value = 0;

	for(int i = 0; i < N; i++)
	{
		L[i] = read_length();

		if (L[i].value > greater.value)
			greater = L[i];
	}

	long long left = 1;
	long long right = greater.value;
	Length result;
	result.value = 0;

	// Realiza busca binária
	while (left <= right)
	{
		long long middle = (right + left) / 2;
		long long q = 0;

		for (int i = 0; i < N; i++)
		{
			q += L[i].value / middle;
		}

		if (q >= K)
		{
			result.value = middle;
			left = middle + 1;
		}
		else
			right = middle - 1;
	}

	print_length(result);
	free(L);

	return 0;
}

