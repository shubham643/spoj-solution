#include<bits/stdc++.h>
using namespace std;

long long save[100000];

long long findit(long long *a,int n,int i)
{
	if(i>n)
		return 0;
	if(save[i])
		return save[i];
	long long temp=(max(a[i]+findit(a,n,i+2),findit(a,n,i+1)));
	save[i]=temp;
	return temp;
}

int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		int n;
		scanf("%d",&n);
		int i;
		long long a[n];
		for(i=0;i<=n;i++)
			save[i]=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		long long sum=findit(a,n-1,0);
		printf("Case %d: %lld\n",j,sum);
	}
	return 0;
}