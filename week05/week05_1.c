#include <stdio.h>

void	sort(int n, int *arr)
{
	int i;
	int j;
	int tmp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (*(arr+j) > *(arr+j+1))
			{
				tmp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = tmp;
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int	main () 
{
	int n = 7;
    int arr[7] = { 0, 25, 10, 17, 6, 12, 9 };

    sort(n, arr);

	return 0; 
}
