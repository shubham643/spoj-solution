#include<bits/stdc++.h>
using namespace std;

long long multiply(long long a,long long b,long long n)
{
	long long res=0,y=a%n;
	while(b)
	{
		if(b&1)
			res=(res+y)%n;
		y=(y<<1)%n;
		b>>=1;
	}
	return res;
}

long long power(long long a,long long b,long long n)
{
	long long res=1;
	while(b>0)
	{
		if(b&1)
			res=multiply(res,a,n);
		a=multiply(a,a,n);
		b>>=1;
	}
	return res;
}

bool miller_rabin(long long n,int it)
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	if(n%2==0)
		return false;
	long long s=n-1;
	while(s%2==0)
		s>>=1;
	while(it--)
	{
		long long a=rand()%(n-1)+1,temp=s;
		long long mod=power(a,temp,n);
		if(mod==-1||mod==1)
			continue;
		while(temp!=n-1&&mod!=n-1)
		{
			mod=multiply(mod,mod,n);
			temp<<=1;
		}
		if(mod!=n-1)
			return false;
	}
	return true;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		if(miller_rabin(n,18))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}