#include<stdio.h>
void closure(int nfa[][20],int k,int n)
{
	int i,d;
	for(i=0;i<=n;i++)
	{
		d=nfa[k][i];
		if(d==1)
		{
			if(i!=k)
			{
				closure(nfa,i,n);
			}
			else
			{
				printf("[%d]",i+1);
			}
		}
	}	
}
int main()
{
	int nfa[20][20],i,j,n,k,tk,t;
	
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
		closure(nfa,i,n);
	}
}
