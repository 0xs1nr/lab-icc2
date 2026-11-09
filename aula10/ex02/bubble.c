#include <stdio.h>

void output(int v[], int n) { for(int i = 0; i < n; i++) i != n-1 ? printf("%d ", v[i]) : printf("%d\n", v[i]); }

void swap(int *a, int *b);
void bubble_sort(int v[], int n);

int main()
{
	int n;
	scanf("%d", &n);

	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	bubble_sort(v, n);

	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int v[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(v[j] > v[j+1])
			{
				swap(&v[j], &v[j+1]);
				output(v, n);
			}
		}
	}
}

