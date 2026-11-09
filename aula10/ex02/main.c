#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void output(int v[], int n) { for(int i = 0; i < n; i++) i != n-1 ? printf("%d ", v[i]) : printf("%d\n", v[i]); }

void swap(int *a, int *b);
int *copy_vector(int v[], int n);
int bubble_sort(int v[], int n);
int insertion_sort(int v[], int n);
int selection_sort(int v[], int n);

int main()
{
	int n;
	scanf("%d", &n);

	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int *u = copy_vector(v, n);
	if(bubble_sort(u, n))
		return 0;

	u = copy_vector(v, n);
	if(insertion_sort(u, n))
		return 0;

	u = copy_vector(v, n);
	if(selection_sort(u, n))
		return 0;

	free(u);
	u = NULL;

	return 0;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int *copy_vector(int v[], int n)
{
	int *u = malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++)
		u[i] = v[i];

	return u;
}

int compare_input(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);

		// printf("x = %d / v[%d] = %d\n", x, i, v[i]);
		if(v[i] != x)
			return 0;
	}

	return 1;
}

int bubble_sort(int v[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(v[j] > v[j+1])
			{
				swap(&v[j], &v[j+1]);
				// output(v, n);
				if(!compare_input(v, n))
					return 0;
			}
		}
	}

	puts("BUBBLE");
	return 1;
}

int insertion_sort(int v[], int n)
{
	for(int i = 1; i < n; i++)
	{
		for(int j = i; v[j] < v[j-1] && j > 0; j--)
		{
			swap(&v[j], &v[j-1]);
			// output(v, n);
			if(!compare_input(v, n))
				return 0;
		}
	}

	puts("INSERTION");
	return 1;
}

int selection_sort(int v[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int min = INT_MAX;
		int pos = i;
		for(int j = i; j < n; j++)
		{
			if(v[j] < min)
			{
				min = v[j];
				pos = j;
			}
		}

		swap(&v[pos], &v[i]);
		// output(v, n);
		if(!compare_input(v, n))
			return 0;
	}

	puts("SELECTION");
	return 1;
}
