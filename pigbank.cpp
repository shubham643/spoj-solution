#include<bits/stdc++.h>
using namespace std;

int findit(int n,int *wt,int *val,int w,int minwt)
{
	static int save[10001][501];
	int i,j;
	for(i=0;i<=w;i++)
		for(j=0;j<=n;j++)
			save[i][j]=9999999;
	for(i=0;i<=n;i++)
		save[0][i]=0;
	for(i=minwt;i<=w;i++)
	{
		for(j=1;j<=n;j++)
		{
			int temp,k=0;
			while(wt[j]*k<=i)
			{
				save[i][j]=min(save[i][j],val[j]*k+save[i-wt[j]*k][j-1]);
				k++;
			}
		}
	}
	return save[w][n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int e,f;
		scanf("%d%d",&e,&f);
		int w=f-e;
		int n;
		scanf("%d",&n);
		int wt[n+1],val[n+1];
		int i,minwt=9999999;
		for(i=1;i<=n;i++){
			scanf("%d%d",&val[i],&wt[i]);
			if(wt[i]<minwt)
				minwt=wt[i];
		}
		int res=findit(n,wt,val,w,minwt);
		if(res==9999999)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",res);
	}
	return 0;
}