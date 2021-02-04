#include <stdio.h>

int	main ()
{
	int n;
	int m;
	int i;

	printf("Room Scale: ");
	scanf("%d %d", &n, &m);

	int block[n];
	int max;
	int idx1;
	int idx2;
	int res;

	idx1 = 0;
	idx2 = 0;
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &block[i]);
		if (block[i] > m)
		{
			printf("Error");
			return (1);
		}
		if (i == 0)
			max = block[0];
		else if (block[i] > max)
		{
			max = block[i];
			idx1 = i;
		}
		else if (max == block[i])
			idx2++;
	}
	res = n - idx1 - idx2 - 1;

	if (res < 0 )
		printf("Error");
	else
		printf("Output: %d", res);
	return (0);
}
