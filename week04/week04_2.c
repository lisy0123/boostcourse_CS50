#include <stdio.h>

int	main ()
{
	int i;
	int num;

	printf("Array Num: ");
	scanf("%d", &num);
	
	int input[num];
	int sum;

	sum = 0;
	printf("** Input EX) 1 2 3 4\nInput: ");
	for (i = 0; i<num; i++)
	{	scanf("%d", &input[i]);
		sum += input[i];
	}
	sum /= num;

	printf("Output: %d", sum);

	return (0);
}
