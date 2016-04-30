#include<bits/stdc++.h>
using namespace std;

long long a[1000001];

int main()
{
	int t,k;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		int n;
		scanf("%d",&n);
		int i;
		long long count=0,minm=INT_MAX;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			count+=a[i];
			if(count<minm)
				minm=count;
		}
		printf("Scenario #%d: ",k);
		if(minm<=0)
			printf("%lld\n",-1*minm+1);
		else
			printf("1\n");
	}
	return 0;
}