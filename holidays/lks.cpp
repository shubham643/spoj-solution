#include<iostream>
#include<stdio.h>
#define ll int
using namespace std;

ll findit(ll n,ll *value,ll *wt,ll minm,ll k)
{
	ll i,j;
	ll save[k+1][n+1];
	for(i=minm;i<=k;i++)
		save[i][0]=0;
	for(i=0;i<=k;i++)
		for(j=0;j<=n;j++)
			save[i][j]=0;
	for(i=minm;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			ll with=(i>=wt[j-1])?(value[j-1]+save[i-wt[j-1]][j-1]):(save[i][j-1]);
			ll without=save[i][j-1];
			save[i][j]=max(with,without);
		}
	}
	return save[k][n];
}

int main()
{
	ll k,n;
	scanf("%d%d",&k,&n);
	ll i,minm=99999999;
	ll value[n],wt[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&value[i],&wt[i]);
		if(wt[i]<minm)
			minm=wt[i];
	}
	cout<<findit(n,value,wt,minm,k);
	return 0;
}