#include<bits/stdc++.h>
using namespace std;

int save[100];
bool flag[100];
int indexed;

void sieve()
{
	int i,j;
	for(i=3;i*i<=100;i+=2)
	{
		if(!flag[i]&&(i&1))
		{
			save[++indexed]=i;
			for(j=i*i;j<=100;j+=2*i)
				flag[j]=true;
		}
	}
	for(i;i<=100;i++)
	{
		if(!flag[i]&&(i&1))
		{
			save[++indexed]=i;
		}
	}
}

int main()
{
	indexed=-1;
	int t;
	sieve();
	for(int i=0;i<=indexed;i++)
		cout<<save[i]<<" ";
	return 0;
}