#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int val[10000001];

void seive()
{
	int i,j;
	for(i=2;i*i<=10000000;i++)
	{
		if(val[i]==0)
		{

			val[i]=i;		
			for(j=i*i;j<=10000000;j+=i)
			{
				if(!val[j])
					val[j]=i;
			}
		}
	}
	val[0]=1;
}

void findit(int t)
{
	int i;
	printf("1");
	while(t!=1)
	{
		if(val[t]!=0)
			printf(" x %d",val[t]);
		else
		{
			printf(" x %d",t);
			break;
		}
		t=t/val[t];
	}
}

int main()
{
	int t;
	seive();
	while(scanf("%d",&t)!=EOF)
	{
		findit(t);
		printf("\n");
	}
	return 0;
}