#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int a[10000];

int main()
{
	long long t;
	scanf("%lld",&t);
	long long g=t;
	while(g--)
	{
		long long n,f;
		scanf("%lld%lld",&f,&n);
		long long i;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		i=n-1;
		long long sum=0;
		while(i>=0&&sum<f)
			sum+=(long)a[i--];
		if(sum>=f)
			printf("Scenario #%lld:\n%lld\n",t-g,n-i-1);
		else
			printf("Scenario #%lld:\nimpossible\n",t-g);
	}
	return 0;
}