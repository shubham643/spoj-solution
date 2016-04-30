#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,a,d;
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		n=2*z/(x+y)-3;
		printf("%lld\n",n+3);
		a=x+(2*x-2*y)/(n-2);
		d=(y-x)/(n-2);
		long long i;
		for(i=0;i<n+3;i++)
			printf("%lld ",a+i*d);
		printf("\n");
	}
	return 0;
}