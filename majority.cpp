#include<iostream>
#include<stdio.h>
using namespace std;

int arr[1000002];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i,val;
		for(i=0;i<1000002;i++)
			arr[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&val);
			arr[1001+val]++;
		}
		int max=0,save;
		for(i=0;i<1000002;i++)
		{
			if(arr[i]>max)
			{
				max=arr[i];
				save=i-1001;
			}
		}
		float temp=n/2.0;
		if(max*1.0>temp)
			printf("YES %d\n",save);
		else
			printf("NO\n");
	}
	return 0;
}