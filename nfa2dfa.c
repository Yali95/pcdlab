#include<stdio.h>
struct state{
char name;
int states[10],clos;
int moves[2][10],mv;
};

int curState;
int nfa[20][20],n;
struct state dfa[10];
void closure(int nfa[][20],int k)
{
int i,d;
for(i=0;i<=n;i++)
{
d=nfa[k][i];
if(d==1)
{
if(i!=k)
{
closure(nfa,i);
}
else
{
printf("[%d]",i+1);
dfa[curState].states[dfa[curState].clos]=i;  //Storing closure in the struct
dfa[curState].clos++;
}
}
}	
}

void moving(int k)
{
int i,tm;
for(i=0;i<=n;i++)
{
tm=nfa[k][i];
if(tm==2)
{
dfa[curState].moves[0][dfa[curState].mv]=i;
dfa[curState].mv++;
}
}
}

int main()
{
	int i,j,k,tk,t;
	
	printf("\nEnter the no. of states : ");
	scanf("%d",&n);
	n--;
	printf("\nEnter the transition table\n");
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			scanf("%d",&nfa[i][j]);
		}
	printf("\n");
	}

	printf("\nThe Transition Table :\n");
	for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=n;j++)
		{
			printf("%d\t",nfa[i][j]);
		}	
	}
/*
	printf("\nE-Closure \nEnter the state : \t");
	scanf("%d",&k);
	printf("\nE-Closure of %d :\n",k);
	k--;
*/
	for(i=0;i<=n;i++)
	{	
		printf("\n\nE-Closure of %d :\n",i+1);
		curState=i;
		dfa[curState].clos=0;

		closure(nfa,i);
		dfa[curState].clos--;
	}
	
	for(i=0;i<=n;i++)              //Finding the Move
	{	
	dfa[i].mv=0;
	curState=i;
	for(j=0;j<=(dfa[i].clos);j++)
	{
	moving(dfa[i].states[j]);
	dfa[i].mv--;
	}
	}

	for(i=0;i<=n;i++)
	{
	printf("\nState %d:",i);
	printf("\nMoves\n");	
	for(j=0;j<=dfa[i].mv;j++)
	{
	printf("[%d]",dfa[i].moves[0][j]);
	}
	}
	
}
