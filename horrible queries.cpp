#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> a[900001];

void update(long long p,long long q,long long s,long long e,long long index,long long v)
{
	if(p>e||q<s)
		return;
	if(p<=s&&e<=q)
	{
		a[index].second+=v;
		a[index].first+=v*(e-s+1);
	}
	else
	{
		long long mid=(s+e)>>1;
		a[index].first+=v*(min(q,e)-max(p,s)+1);
		index<<=1;
		update(p,q,s,mid,index,v);
		update(p,q,mid+1,e,index+1,v);
	}
}

long long query(long long p,long long q,long long s,long long e,long long index,long long till)
{
	if(p>e||q<s)
		return 0;
	if(p<=s&&q>=e)
		return a[index].first + till*(e-s+1);
	else
	{
		long long mid=(s+e)>>1;
		return query(p,q,s,mid,index*2,till+a[index].second)+query(p,q,mid+1,e,index*2+1,till+a[index].second);
	}
}

int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long c,i;
		scanf("%lld",&c);
		long long temp=ceil(log2(n));
		temp=2*(pow(2,temp))+1;
	//	cout<<temp;
		for(i=0;i<=temp;i++)
			a[i].first=a[i].second=0;
		while(c--)
		{
			long long type,p,q,v;
			scanf("%lld%lld%lld",&type,&p,&q);
			if(type==0)
			{
				scanf("%lld",&v);
				update(p,q,1,n,1,v);
			}
			else
				printf("%lld\n",query(p,q,1,n,1,0));
		}
	}
}