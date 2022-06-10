
#include<stdio.h>
#include <stdlib.h>  
main(void) 
{
	
int *A = 0;
int *B = 0;
int *C = 0;
int *D = 0;	
int *N;
int *M;
int teams[4] = {A,B,C,D}; 
int i, j, f;
char teamsn[4] = {'A', 'B', 'C', 'D'}, g;
int goals_scored [4];
int goals_given [4];
int goals_diff[4];

for(i = 0; i<4; i++) 
{

	for(j = i + 1; j<4; j++) 
		{
			scanf("%d", &N);
			scanf("%d/n", &M);
			goals_scored[i] = N;
			goals_scored[j] = M;
			goals_given[i] = M;
			goals_given[j] = N;
			
	if(N > M) 
		{
			teams[i] += 3; 
		}

	if(N == M) 
		{
			teams[i] += 1;
			teams[j] += 1; 
		}

	if(N < M) 
		{
			teams[j] += 3; 
		}

}


}


for(i=0; i<4; i++)
{
	for(j = 0; j<4; j++) 
		{
			
	if(teams[i] < teams[i+1]) 
		{

			f = teams[i];
			teams[i] = teams[j];
			teams[j] = f;

			g = teamsn[i];
			teamsn[i] = teamsn[j];
			teamsn[j] = g;

		}

		}
 
}

for(i = 0;i<4;i++)
{
	goals_diff[i] = goals_scored[i] - goals_given[i];
}

for(i =0;i<4;i++)
{
	for(j = i+1;j<4;j++)
	{
		if(teams[i] == teams[j])
		{
			if(goals_diff[i] > goals_diff[j])
			{
				g = teamsn[i];
				teamsn[i] = teamsn[j];
				teamsn[j] = f;
			}
			if(goals_diff[i] == goals_diff[j])
			{
				if(goals_scored[i] > goals_scored[j])
				{
				g = teamsn[i];
				teamsn[i] = teamsn[j];
				teamsn[j] = f;
				}
			}
		}
	}
}

printf("The ranking of the teams is ");

for(i = 0; i<4; i++) 
	{
		printf("%c", teamsn[i]);
	}

printf("\n");

}

