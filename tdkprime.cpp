#include<bits/stdc++.h>
using namespace std;

bool flag[10000000];
int saved[10000000];
int another[10000000];
int indexed;
int counting;

void compute()
{
//	saved[++indexed]=2;
	int i,j;
	int b=10000;
	for(i=2;i<=b;i++)
	{
		if(!flag[i])
		{
			saved[++indexed]=i;
			for(j=i*i;j<10000000;j+=i)
				flag[j]=true;
		}
	}
	counting=indexed+1;
	for(i;i<10000000;i++)
	{
		if(!flag[i]){
			another[counting++]=i;
		}
	}
}

void findit(int a,int b)
{
	int i,j;
	for(i=0;i<=indexed;i++)
	{
		j=saved[i]-a%saved[i];
		if(j==saved[i])
			flag[0]=true;
		for(j;j<10000000;j+=saved[i])
			flag[j]=true;
	}
	for(i=0;i<b-a;i++)
	{
		if(!flag[i]){
			another[counting]=a+i;
			counting++;
		}
	}
}

void findit8(int a,int b)
{
	int i,j;
	for(i=0;i<=indexed;i++)
	{
		j=saved[i]-a%saved[i];
		if(j==saved[i])
			flag[0]=true;
		for(j;j<10000000;j+=saved[i])
			flag[j]=true;
	}
	for(i=0;i<b-a;i++)
	{
		if(!flag[i]&&((i+a)&1)){
			another[counting]=a+i;
			counting++;
			if(counting==5000001)
				return;
		}
	}
}

int main()
{
	indexed=-1;
	compute();
	int i;
	for(i=1;i<=9;i++)
	{
		int j;
		for(j=0;j<10000000;j++)
			flag[j]=false;
		if(i==8)
			findit8(i*10000000,(i+1)*10000000);
		else
			findit(i*10000000,(i+1)*10000000);
		if(counting>=5000001)
			break;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(i<=indexed)
			printf("%d\n",saved[n-1]);
		else
			printf("%d\n",another[n-indexed+1]);
	}
	return 0;
}