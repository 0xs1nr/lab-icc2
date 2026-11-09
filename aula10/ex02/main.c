#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void output(int v[], int n) { for(int i = 0; i < n; i++) i != n-1 ? printf("%d ", v[i]) : printf("%d\n", v[i]); }

void swap(int *a, int *b);
int *copy_vector(int v[], int n);
int compare_input(int v[], int n, int *steps[], int i);
int bubble_sort(int v[], int n, int *steps[]);
int insertion_sort(int v[], int n, int *steps[]);
int selection_sort(int v[], int n, int *steps[]);

int main()
{
	int n;
	scanf("%d", &n);

	int v[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	int **steps = malloc(sizeof(int) * (n-1)*n);
	if(!steps)
		return -1;

	for(int i = 0; i < n-1; i++)
	{
		steps[i] = malloc(sizeof(int) * n);
	}

	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n; j++)
			scanf("%d", &steps[i][j]);
	}


	int *u = copy_vector(v, n);
	if(bubble_sort(u, n, steps))
		return 0;

	u = copy_vector(v, n);
	if(insertion_sort(u, n, steps))
		return 0;

	u = copy_vector(v, n);
	if(selection_sort(u, n, steps))
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

int compare_input(int v[], int n, int *steps[], int i)
{
	for(int j = 0; j < n; j++)
	{
		if(v[j] != steps[i][j])
			return 0;
	}

	return 1;
}

int bubble_sort(int v[], int n, int *steps[])
{
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
			if(v[j] > v[j+1])
			{
				swap(&v[j], &v[j+1]);
			}
		}
		if(!compare_input(v, n, steps, i))
			return 0;

	}

	puts("BUBBLE");
	return 1;
}

int insertion_sort(int v[], int n, int *steps[])
{
	for(int i = 1; i < n; i++)
	{
		for(int j = i; v[j] < v[j-1] && j > 0; j--)
		{
			swap(&v[j], &v[j-1]);
		}
		// output(v, n);
		if(!compare_input(v, n, steps, i-1))
			return 0;

	}

	puts("INSERTION");
	return 1;
}

int selection_sort(int v[], int n, int *steps[])
{
	for(int i = 0; i < n-1; i++)
	{
		int min_idx = i;
		for(int j = i+1; j < n; j++)
		{
			if(v[j] < v[min_idx])
				min_idx = j;	
		}

		swap(&v[i], &v[min_idx]);
		if(!compare_input(v, n, steps, i))
			return 0;
	}

	puts("SELECTION");
	return 1;
}
