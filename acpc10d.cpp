#include<bits/stdc++.h>
using namespace std;

int main()
{
	int cnt=1;
	long long n;
	while(1)
	{
		scanf("%lld",&n);

		if(n==0)
			break;
		long long save[n][3];
		long long res[n][3];
		long long i;
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld",&save[i][0],&save[i][1],&save[i][2]);
		}
		long long final=save[n-1][1];
		res[n-1][1]=final;
		res[0][1]=save[0][1];
		res[n-1][0]=save[n-1][0]+final;
		res[n-1][2]=INT_MAX;
		for(i=n-2;i>=0;i--)
		{
			res[i][2]=min(res[i+1][1],res[i+1][2])+save[i][2];	
			res[i][1]=min(res[i+1][0],min(res[i+1][1],min(res[i+1][2],res[i][2])))+save[i][1];
			res[i][0]=save[i][0]+min(res[i+1][0],min(res[i+1][1],res[i][1]));
		}
		printf("%d. %lld\n",cnt,res[0][1]);
		cnt++;
	}
	return 0;
}