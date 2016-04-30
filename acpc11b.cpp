#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n1,n2;
		scanf("%d",&n1);
		int a[n1];
		int i;
		for(i=0;i<n1;i++)
			scanf("%d",&a[i]);
		scanf("%d",&n2);
		int b[n2];
		for(i=0;i<n2;i++)
			scanf("%d",&b[i]);
		sort(a,a+n1);
		sort(b,b+n2);
		int j;
		i=j=0;
		int save=99999999;
		while(i<n1&&j<n2)
		{
			if(a[i]>b[j])
			{
				if(a[i]-b[j]<save)
					save=a[i]-b[j];
				j++;
			}
			else
			{
				if(b[j]-a[i]<save)
					save=b[j]-a[i];
				i++;	
			}
		}
		printf("%d\n",save);
	}
	return 0;
}