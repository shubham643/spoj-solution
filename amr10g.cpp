#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i;
		scanf("%d%d",&n,&k);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int dif=1000000000;
		for(i=0;i<=n-k;i++){
			if(a[i+k-1]-a[i]<dif)
				dif=a[i+k-1]-a[i];
		}
		printf("%d\n",dif);
	}
	return 0;
}