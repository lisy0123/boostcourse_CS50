#include <stdio.h>
#include <string.h>

int	main ()
{
	char date[4];

	printf("요일을 입력하세요: ");
	scanf("%s", date);
	
	if (strcmp(date, "월요일") == 0)
		printf("%s: 청국장", date);	
	else if (strcmp(date, "화요일") == 0)
		printf("%s: 비빔밥", date);
	else if (strcmp(date, "수요일") == 0)
		printf("%s: 된장찌개", date);
	else if (strcmp(date, "목요일") == 0)
		printf("%s: 칼국수", date);
	else if (strcmp(date, "금요일") == 0)
		printf("%s: 냉면", date);
	else if (strcmp(date, "토요일") == 0)
		printf("%s: 소불고기", date);
	else if (strcmp(date, "일요일") == 0)
		printf("%s: 오삼불고기", date);
	else
		printf("Error");
	return (0);
}
