#include<bits/stdc++.h>
using namespace std;

long long findit(long long a,long long b)
{
	if(b>a)
	{
		long long temp=a;
		a=b;
		b=temp;
	}
	while(b)
	{
		long long temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}

int main()
{
	long long t;
	scanf("%lld",&t);
	long long i;
	for(i=1;i<=t;i++)
	{
		long long a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a==b&&a==0){
			printf("Case %lld: 0\n",i);
			continue;
		}
		long long down=(a+b)*(c+d+1);
		long long up=a*(c+1)+b*(d+1);
		long long gcd=findit(up,down);
		up/=gcd;
		down/=gcd;
		printf("Case %lld: %lld/%lld\n",i,up,down);
	}
	return 0;
}