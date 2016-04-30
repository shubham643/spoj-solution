#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(1)
	{
		int i;
		scanf("%d",&n);
		if(n==0)
			break;
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int last=0;
		for(i=1;i<n;i++)
		{
			if(a[i]-last>200)
				break;
			else
				last=a[i];
		}
		if(i==n){
			int dis=1422-a[n-1];
			dis=2*dis;
			if(dis>200)
				cout<<"IMPOSSIBLE\n";
			else
				cout<<"POSSIBLE\n";
		}
		else
			cout<<"IMPOSSIBLE\n";
	}
	return 0;
}