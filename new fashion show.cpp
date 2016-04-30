#include<iostream>
#include<stdio.h>
#include<algorithm>
#define ll long long
using namespace std;

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll a[n],val,i,b[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
                sort(a,a+n);
		ll sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&b[i]);
		}
		sort(b,b+n);
		sum=0;
		for(i=0;i<n;i++)
		    sum+=a[i]*b[i];
		printf("%lld\n",sum);
	}
	return 0;
}


