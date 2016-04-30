#include<bits/stdc++.h>
using namespace std;

long long save[1000000];

void construct(long long *a,long long s,long long e,long long index)
{
	if(s==e){
		save[index]=a[s];
	}
	else
	{
		long long mid=(s+e);
		mid=mid>>1;
		construct(a,s,mid,2*index);
		construct(a,mid+1,e,2*index+1);
		save[index]=max(save[2*index],save[2*index+1]);
	}
}

long long findit(long long x,long long y,long long index,long long rl,long long rr)
{
	if(x<=rl&&y>=rr){
		return save[index];
	}
	else if(x>rr||y<rl)
		return -1;
	else
	{
		long long mid=(rl+rr)>>1;
		long long p=findit(x,y,index*2,rl,mid);
		long long q=findit(x,y,index*2+1,mid+1,rr);
		return max(p,q);
	}
}

int main()
{
	long long n;
	scanf("%lld",&n);
	long long i;
	long long a[n+1];
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	construct(a,1,n,1);
	long long m,x,y,ans=0;
	scanf("%lld%lld%lld",&m,&x,&y);
	ans+=findit(min(x+1,y+1),max(x+1,y+1),1,1,n);
//	cout<<ans<<" ";
	for(i=2;i<=m;i++)
	{
		x=(x+7)%(n-1);
		y=(y+11)%n;
		long long p=x+1;
		long long q=y+1;
		long long res=findit(min(p,q),max(p,q),1,1,n);
		ans+=res;
	}
	printf("%lld",ans);
	return 0;
}