#include<bits/stdc++.h>
using namespace std;

long long findgcd(long long a,long long b)
{
	if(a>b)
	{
		long long temp=a;
		a=b;
		b=temp;
	}
	while(a)
	{
		long long temp=a;
		a=b%a;
		b=temp;
	}
	return b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,n;
		scanf("%lld%lld%lld",&a,&b,&n);
		long long gcd=findgcd(a,b);
		gcd=a*b/gcd;
		long long count=gcd/a + gcd/b -1;
		long long res=n/count*gcd;
		long long rem=n%count;
		long long step=n%count,i=0,j=0;
		long long tempa=res,tempb=res;
		while(step)
		{
			if(tempa+a<tempb+b)
				tempa+=a;
			else
				tempb+=b;
			step--;
		}
		printf("%lld\n",max(tempa,tempb));
	}
	return 0;
}