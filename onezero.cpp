#include<bits/stdc++.h>
using namespace std;

int countdig(int n)
{
	if(n<10)
		return 1;
	else if(n<100)
		return 2;
	else if(n<1000)
		return 3;
	else
		return 4;
}

int finddec(int n)
{
	int num=1;
	int res=0;
	if(n%10)
		res=1;
	n/=10;
	while(n)
	{
		num*=2;
		if(n%10)
			res+=num;
		n/=10;
	}
	return res;
}

long long tobinary(int dec)
{
	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,dig;
		dig=countdig(n);
		int temp=(i-1)*10;
		if(temp<n&&temp+1>=n)
			temp++;
		else
			temp*=10;
		int dec=finddec(temp);
		while(1)
		{
			long long val=tobinary(dec);
			if(val%n==0)
				break;
			dec++;
		}
		printf("%lld\n",val);
	}
	return 0;
}