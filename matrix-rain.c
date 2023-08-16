#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void main()
{
	srand(time(NULL));
	int matrix[50][210][2];
	int colseed,ii,whichcolumn,till,count=0;
	for(int i=0;i<50;i++)
	{
		for(int j=0;j<210;j++)
		{
			matrix[i][j][0]=32;
			matrix[i][j][1]=-1;
		}
	}


	while(1)
	{
		for(int i=1;i<50;i++)
		{
			for(int j=0;j<210;j++)
			{
				if(matrix[i][j][1]==-1 && matrix[i-1][j][1]>=1)
				{
					matrix[i][j][0]=rand()%(127-33)+33;
					matrix[i][j][1]=0;
				}
			}
		}
		colseed=rand()%100;
		if(colseed<70)
		{
			ii=0;
		}
		else if(colseed<90)
		{
			ii=1;
		}
		else if(colseed<95)
		{
			ii=2;
		}
		else
		{
			ii=3;
		}
		while(ii>0)
		{
			whichcolumn=rand()%210;
			for(int i=1;i<50;i++)
			{
				if(matrix[i][whichcolumn][1]==0)
				{
					count++;
				}
			}
			if((matrix[0][whichcolumn][0]==32)&&count<4)
			{
				matrix[0][whichcolumn][0]=rand()%(127-33)+33;
				matrix[0][whichcolumn][1]=0;
				ii--;
			}
			count=0;
		}
		
		for(int i=0;i<50;i++)
		{
			for(int j=0;j<210;j++)
			{
				till=rand()%100;
				if(till<50)
				{
					till=rand()%7+3;
				}
				else if(till<80)
				{
					till=rand()%9+5;
				}
				else if(till<90)
				{
					till=rand()%11+7;
				}
				else if(till<93)
				{
					till=rand()%13+8;
				}
				else if(till<96)
				{
					till=rand()%16+9;
				}
				else if(till<98)
				{
					till=rand()%19+10;
				}
				else
				{
					till=rand()%22+11;
				}
				
				if(matrix[i][j][1]==0)
				{
					printf("\033[1;97m");
					count++;
				}
				else if(matrix[i][j][1]<=((int)till/2))
				{
					printf("\033[1;32m");
				}
				else if(matrix[i][j][1]<=till)
				{
					printf("\033[0;92m");
				}
				else if(matrix[i][j][1]>till)
				{
					matrix[i][j][0]=32;
					matrix[i][j][1]=-1;
				}
				printf("%c",((char)matrix[i][j][0]));
				if(matrix[i][j][0]!=32)
				{
					matrix[i][j][1]++;
				}
			}
			printf("\n");
		}
		struct timespec req = {.tv_sec = 0, .tv_nsec = 100000000};  // 150 milliseconds
   		nanosleep(&req, NULL);
		printf("\e[2J\e[H");
		fflush(stdout);
	}
}
