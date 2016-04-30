#include<bits/stdc++.h>
#define MAXM 9999999
using namespace std;


long long bysum(long long *a,long long i,long long k,long long j,long long *st)
{
	long long f=(st[k]-st[i-1])%100;
	long long s=(st[j]-st[k])%100;

	return f*s;
}

long long perform(long long *a,long long n)
{
	long long st[n+1];
	long long i;
	long long l,j,lastpt,k;
	st[0]=0;
	st[1]=a[1];
	for(i=2;i<=n;i++)
		st[i]=st[i-1]+a[i];
	long long mat[n+1][n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			mat[i][j]=MAXM;
	}
	for(i=0;i<=n;i++)
		mat[i][i]=0;
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			long long lastpt=i+l-1;
		
			for(k=i;k<=lastpt-1;k++)
			{
				long long temp=mat[i][k]+mat[k+1][lastpt]+bysum(a,i,k,lastpt,st);
				if(temp<mat[i][lastpt])
					mat[i][lastpt]=temp;
			}
		}
	}

	return mat[1][n];
}

int main()
{
	long long n;
	while(scanf("%lld",&n)>0)
	{
		long long i,res;
		long long a[n+1];
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		res=perform(a,n);
		printf("%d\n",res);
	}
	return 0;
}