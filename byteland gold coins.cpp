#include<iostream>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;

ll arr[1000000];

ll findit(ll n)
{
	if(n==0||n==1||n==2||n==3||n==4||n==5)
		return n;
    if(arr[n])
		return arr[n];
	if(n>=1000000)
		return(findit(n/2)+findit(n/3)+findit(n/4));
    else
	{
		ll count=(findit(n/2)+findit(n/3)+findit(n/4));
		if(count>=n)
		{
			arr[n]=count;
			return count;
		}
		else
		{
			arr[n]=n;
			return n;
		}
	}
}

int main()
{
	ll n;
	while(scanf("%lld",&n)!=EOF)
	{
		ll ways=findit(n);
		printf("%lld\n",ways);
	}
	return 0;
}
