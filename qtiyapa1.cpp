#include<bits/stdc++.h>
using namespace std;

unsigned long long power(unsigned long long a,unsigned long long b,unsigned long long n)
{
	unsigned long long res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%n;
		a=(a*a)%n;
		b>>=1;
	}
	return res;
}

unsigned long long multiply(unsigned long long a,unsigned long long b,unsigned long long n)
{
	unsigned long long res=0,y=a%c;
	while(b)
	{
		if(b&1)
			res=(res+y)%n;
		y=(y<<1)%c;
		b>>=1;
	}
	return res;
}

bool miller_rabin(unsigned long long n,int it)
{
	if(n<2)
		return false;
	if(n==2)
		return true;
	if(n%2==0)
		return false;
	unsigned long long s=n-1;
	while(s%2==0)
		s>>=1;
	while(it--)
	{
		unsigned long long a=rand()%(p-1)+1,temp=s;
		unsigned long long mod=power(a,temp,n);
		if(mod==-1||mod==1)
			continue;
		while(temp!=n-1&&mod!=n-1)
		{
			mod=multiply(mod,mod,n);
			temp<<=1;
		}
		if(mod!p-1)
			return false;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long n;
		scanf("%llu",&n);
		if(miller_rabin(n,18))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}