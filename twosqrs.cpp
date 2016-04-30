#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool findit(ll n)
{
	if(n%4==3)
		return false;
	else
	{
		ll b=sqrt(n);
		ll a=0;
		while(a<=sqrt(n))
		{
			ll temp=a*a+b*b;
			if(temp==n)
				return true;
			else if(temp<n)
				a++;
			else
				b--;
		}
		return false;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		if(findit(n))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}