#include<bits/stdc++.h>
#define mod 1000007
#define ll long long
using namespace std;

ll save[1000007];

void compute()
{
	ll i;
	ll res=0;
	for(i=1;i<=1000000;i++)
	{
		save[i]=(save[i-1]+(2*i)%mod+(i-1)%mod)%mod;
	}
}

int main()
{
	int t;
	compute();
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",save[n]);
	}
	return 0;
}