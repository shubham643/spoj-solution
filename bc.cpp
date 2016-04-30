#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int i;
	for(i=1;i<=t;i++)
	{
		double n,m,k;
		scanf("%lf%lf%lf",&n,&m,&k);
		long long byhand=m*k*n-1;
		int without=0;
		while(n>1)
		{
			n/=2;
			without++;
		}
		while(m>1)
		{
			m/=2;
			without++;
		}
		while(k>1)
		{
			k/=2;
			without++;
		}
		printf("Case #%d: %ld %d\n",i,byhand,without);
	}
	return 0;
}