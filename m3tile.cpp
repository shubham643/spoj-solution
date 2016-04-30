#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	int i;
	long long a[31];
	a[1]=0;
	a[0]=1;
	a[2]=3;
	a[3]=0;
	a[4]=11;
	for(i=5;i<=30;i++)
	{
		a[i]=4*a[i-2]-a[i-4];
	}
	while(1)
	{
		scanf("%lld",&n);
		if(n==-1)
			break;
		printf("%lld\n",a[n]);
	}
	return 0;
}