#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

char * formulaTime(int s, int m, int h)
{
	// Allocating 9 memory cases for the clock; 8 for the printed characters and 1 for the '\0' character
	char* clockForm = (char*)calloc(9,sizeof(char));
	
	// Fixing the display for the seconds part of the clock; 2 possible cases, for values under 10, and 10 till 59
	if(s >= 10)
	{
		*(clockForm + 6) = (char)(48 + (s / 10));
		*(clockForm + 7) = (char)(48 + ((int)(s % 10)));
	}
	else
	{
		*(clockForm + 6)= '0';
		*(clockForm + 7) = (char)(48 + s);		
	}
	
	// The minutes' dispaly; same idea as for the seconds part
	if(m >= 10)
	{
		*(clockForm + 3) = (char)(48 + (m / 10));
		*(clockForm + 4) = (char)(48 + ((int)(m % 10)));
	}
	else
	{
		*(clockForm + 3) = '0';
		*(clockForm + 4) = (char)(48 + m);		
	}
	
	// Fixing the display for the seconds part of the clock; 2 possible cases, for values under 10, and 10 till 23
	if(h >= 10)
	{
		*clockForm = (char)(48 + (h / 10));
		*(clockForm + 1) = (char)(48 + ((int)(h % 10)));
	}
	else
	{
		*clockForm = '0';
		*(clockForm + 1) = (char)(48 + h);		
	}
	*(clockForm + 2) = ':';
	*(clockForm + 5) = ':';
	return clockForm;
}

int main()
{
	int s = 0, m = 0, h = 0;
	while(1)
	{
		printf("%s",formulaTime(s++,m,h));
		if(s > 59)
		{
			s = 0;
			m++;
		}
		if(m > 59)
		{
			m = 0;
			h++;
		}
		if(h > 23)
		{
			s = 0;
			m = 0;
			h = 0;
		}
		sleep(1);
		system("cls");
	}
	return 0;
}
