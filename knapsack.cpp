#include<bits/stdc++.h>
using namespace std;

int save[2001][2001];

int findit(int n,int *val,int *wt,int k)
{
	int i,j;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			int with=i>=wt[j]?val[j]+save[i-wt[j]][j-1]:(save[i][j-1]);
			int without=save[i][j-1];
			save[i][j]=max(with,without);
		}
	}
	return save[k][n];
}

int main()
{
	int n,k;
	scanf("%d%d",&k,&n);
	int wt[n+1],val[n+1],i;
	for(i=1;i<=n;i++)
		scanf("%d%d",&wt[i],&val[i]);
	int res=findit(n,val,wt,k);
	cout<<res;
	return 0;
}