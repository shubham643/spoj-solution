#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	long long a[n],sum[n];
	int i;
	scanf("%lld",&a[0]);
	sum[0]=a[0];
	for(i=1;i<n;i++){
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	int l,r;
	l=r=0;
	long long res=0,temp=0;
	while(r<n)
	{
		if(l==0)
			temp=sum[r];
		else
			temp=sum[r]-sum[l-1];
		if(temp==m)
		{
			res=temp;
			break;
		}
		else if(temp<m)
		{
			if(temp>res)
				res=temp;
			r++;
		}
		else
		{
			l++;
		}
	}
	printf("%lld",res);
}