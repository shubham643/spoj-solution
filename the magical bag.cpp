#include<iostream>
#include<stdio.h>
#define ll long long
#define MODULO 1000000007
using namespace std;

ll findpow(ll p,ll n)
{
	p%=MODULO;
	ll res=1;
	while(n)
	{
		if(n&1)
		{
			res=(res*p)%MODULO;
		}
		n/=2;
		p=(p*p)%MODULO;
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,p;
		scanf("%lld%lld",&n,&p);
		ll pn=findpow(p,n);
		ll pnminus=findpow(p,n-1);
		ll a=(pn-1)%MODULO;
		a=(a*findpow(p-1,MODULO-2))%MODULO;
		printf("%lld %lld\n",a,pnminus);
	}
	return 0;
}