/*input
3
3
14
7
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		ll x=(sqrt(1+8*n)-1)/2;
		ll sum=x*(x+1)/2;
		if(x%2==0)
		{
			if(sum!=n)
				printf("TERM %lld IS %lld/%lld\n",n,x+2-(n-sum),n-sum);
			else
				printf("TERM %lld IS %lld/1\n",n,x);
		}
		else
		{
			if(sum!=n)
				printf("TERM %lld IS %lld/%lld\n",n,n-sum,x+2-(n-sum));
			else
				printf("TERM %lld IS 1/%lld\n",n,x);
		}
	}
	return 0;
}