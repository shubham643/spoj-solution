#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int t;
	while(1)
	{
		scanf("%d",&t);
		if(t==-1)
			return 0;
		int sum=0;
		int i;
		int a[t];
		for(i=0;i<t;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%t!=0)
			printf("-1");
		else
		{
			int count=0;
			sum/=t;
			for(i=0;i<t;i++)
			{
				if(a[i]>sum)
					count+=a[i]-sum;
			}
			printf("%d",count);
		}
		printf("\n");
	}
	return 0;
}