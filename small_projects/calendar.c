//CALENDAR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calendar(int year, int *srt, int mth);

int main()
{
	int year, srt, op, i;
	printf("Year?: \n");
	scanf("%d", &year);
	srt = (((year-1)*365)+((year-1)/4)-((year-1)/100)+((year-1)/400))%7;
	i = 0;
	system("cls");
	printf("CALENDAR FOR THE YEAR: %d\n\n", year);
	while(i < 12){
		calendar(year, &srt, i);
		printf("\n");
		++i;
	}
	printf("Do again for another year?\n");
	printf("[0]. No.\n");
	printf("[1]. Yes.\n");
	scanf("%d", &op);
	if(op == 1) main();
	return 0;
}

//Function used to print one month in the calendar.

void calendar(int year, int *srt, int mth)
{
	int i, j, daycount, limit, aux, control;
	char days[7][10] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};  
	char month[12][10] = {"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
	daycount = 1;
	control = 0;
	aux = *srt;
	if(mth == 0 || mth == 2 || mth == 4 || mth == 6 || mth == 7 || mth == 9 || mth == 11) limit = 31;
	else if(mth == 3 || mth == 5 || mth == 8 || mth == 10) limit = 30;
	else
	{
		if((!(year%4) && (year%100)) || !(year%400)) limit = 29;
		else limit = 28;
	}
	for(i = 0; i < 8; ++i)
	{
		if(i == 0) printf("%-9s\t\t     %4d",month[mth], year);
		else{
			for(j = 0; j < 7; ++j)
			{
				if(i == 1) printf("%-5s", days[j]);
				else if((i > 2) || (i == 2 && j >= aux))
				{
					printf("%-5d", daycount);
					if(daycount == limit)
					{ 
						aux = j+1;
						control = 1;
					}
					++daycount;
				}
				else printf("     ");
				if(control == 1) break;
			}

		}
		printf("\n");
		if(control == 1) break;
	}
	if(aux == 7) aux = 0;
	*srt = aux;
	return;
}
