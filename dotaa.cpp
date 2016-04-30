#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,d;
		scanf("%d%d%d",&n,&m,&d);
		int i,count=0;
		for(i=0;i<n;i++)
		{
			int val;
			scanf("%d",&val);
			int temp=val/d;
			if(val-temp*d>0)
				count+=temp;
			else if(temp>0)
				count+=temp-1;
		}
		if(m<=count)
			printf("YES");
		else
			printf("NO");
		printf("\n");
	}
	return 0;
}