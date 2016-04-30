#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#define ll long long
using namespace std;

ll findit(ll *arr)
{
	int i=0;
	ll n;
	for(n=192;n<1000;n++)
	{
		ll test=(n*n)%1000;
		test=(test*n)%1000;
		if(test==888)
		{	
			arr[i++]=n;
		}
	}
}

int main()
{
	ll t;
	ll arr[4];
	findit(arr);
	scanf("%lld",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll j;
		j=(n/4);
		if(j*4==n)
		{	
			if(j-1)
				printf("%lld",j-1);
		}
		else if(j)
			printf("%lld",j);
		if(n%4==0)
			printf("%lld\n",arr[3]);
		else
			printf("%lld\n",arr[n%4-1]);
	}
	return 0;
}