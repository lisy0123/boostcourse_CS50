#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	cal_grade(int score, int count, char ***grade)
{
	if (score >= 95)
		strcpy((*grade)[count - 1], "A+");
	else if (score >= 90)
		strcpy((*grade)[count - 1], "A ");
	else if (score >= 85)
		strcpy((*grade)[count - 1], "B+");
	else if (score >= 80)
		strcpy((*grade)[count - 1], "B ");
	else if (score >= 75)
		strcpy((*grade)[count - 1], "C+");
	else if (score >= 70)
		strcpy((*grade)[count - 1], "C ");
	else if (score >= 65)
		strcpy((*grade)[count - 1], "D+");
	else if (score >= 60)
		strcpy((*grade)[count - 1], "D ");
	else
		strcpy((*grade)[count - 1], "F ");
	printf(">>> Your grade is %s", (*grade)[count - 1]);

}

void	save_add(int count, int **save)
{
	int i;
	int *tmp;

	tmp = (int*)malloc(sizeof(int) * count);
	for (i = 0; i < count; i++)
		tmp[i] = (*save)[i];
	free(*save);
	*save = tmp;
}


void	grade_add(int count, char ***grade)
{
	int i;
	int j;
	char **tmp;

	tmp = (char**)malloc(sizeof(char*) * count);
	for (i = 0; i < count; i++)
		tmp[i] = (char*)malloc(sizeof(char) * 3);
	for (i = 0; i < (count - 1); i++)
	{
		for (j = 0; j < 3; j++)
			tmp[i][j] = (*grade)[i][j];
	}
	for(i = 0; i < (count - 1); i++)
		free((*grade)[i]);
	free(*grade);
	*grade = tmp;
}

void	result(int count, int *save, char **grade)
{
	int i;

	if (count > 1)
	{
		printf("\n [ Result Table ]\n\n");
		printf(" Score ┃");
		for (i = 0; i < count - 1; i++)
			printf(" %.3d ┃", save[i]);
		printf("\n━━━━━━━╋");
		for (i = 0; i < count - 1; i++)
			printf("━━━━━╋");
		printf("\n Grade ┃");
		for (i = 0; i < count - 1; i++)
			printf("  %s ┃", grade[i]);
	}
	printf("\n\n<--------- Finish the program --------->\n\n");
	free(save);
	for(i = 0; i < count; i++)
		free(grade[i]);
	free(grade);

}

void	calculate()
{

	int	i;
	int score;
	int count;
	int *save;
	char **grade;

	count = 1;
	save = (int*)malloc(sizeof(int));
	grade = (char**)malloc(sizeof(char*));
	grade[0] = (char*)malloc(sizeof(char) * 3);

	while (1)
	{
		printf("%.2d. Enter your score (0-100): ", count);
		scanf("%d", &score);

		save[count - 1] = score;

		if (score == 999)
			break;
		else if (score <= 100 && score >= 0)
			cal_grade(score, count, &grade);
		else
		{
			printf(">>> Error\n* Please enter a correct score between 1-100.");
			save[count - 1] = 999;
			strcpy(grade[count - 1],"X ");
		}
		printf("\n\n");
		count++;
		save_add(count, &save);
		grade_add(count, &grade);
	}
	result(count, save, grade);
}

int		main ()
{
	printf("\n<------ Grade Calculation Program ------>\n\n");
	printf("If you want to exit, enter '999'\n\n");
	printf("[ Grade Table ]\n\n");
	printf(" Score ┃ 95 ┃ 90 ┃ 85 ┃ 80 ┃ 75 ┃ 70 ┃ 65 ┃ 60 ┃ 0 ┃\n");
	printf("━━━━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━━╋━━━╋\n");
	printf(" Grade ┃ A+ ┃ A  ┃ B+ ┃ B  ┃ C+ ┃ C  ┃ D+ ┃ D  ┃ F ┃\n\n\n");

	calculate();

	return (0);
}
