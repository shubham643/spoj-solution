#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		long a[n],val,i;
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		long sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%ld",&val);
			if(val!=0&&a[i]!=0)
				sum+=val*a[i];
		}
		printf("%ld\n",sum);
	}
	return 0;
}