#include<bits/stdc++.h>
using namespace std;

long long save[2001][2001];

long long findit(long long *a,long long n)
{
	long long i,j,l;
	for(i=1;i<=n;i++)
	{
		save[i][i]=n*a[i];
	}	
	for(l=2;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=i+l-1;
			save[i][j]=max(a[i]*(n-j+i)+save[i+1][j],a[j]*(n-j+i)+save[i][j-1]);
		}
	}
	return save[1][n];
}

int main()
{
	long long n;
	scanf("%lld",&n);
	long long a[n+1];
	long long i;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	long long res=findit(a,n);
	printf("%lld",res);
	return 0;
}