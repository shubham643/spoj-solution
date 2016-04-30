#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(a>b)
	{
		int temp=b;
		b=a;
		a=temp;
	}
	while(a)
	{
		int temp=b%a;
		b=a;
		a=temp;
	}
	return b;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		while(1)
		{
			int g=gcd(a,b);
			if(g==1)
				break;
			a/=g;
			b/=g;
		}
		printf("%d %d\n",b,a);
	}
	return 0;
}