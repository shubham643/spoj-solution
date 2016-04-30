#include<bits/stdc++.h>
#define ll long long
#define mod 
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,res=1,k;
		scanf("%lld%lld",&n,&k);
		ll save=n;
		while(n)
		{
			res=(res)*(n%k+1);
			n/=k;
		}
		printf("%lld\n",1+save-res);
	}
	return 0;
}