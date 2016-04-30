#include<bits/stdc++.h>
using namespace std;

struct node
{
	long long val,reset;
};

node save[300000];

node update(long long x,long long y,long long val,long long rl,long long rr,long long index)
{
	if(x<=rl&&y>=rr)
	{
		save[index].reset+=val;
		save[index].val+=val*(rr-rl+1);
		return save[index];
	}
	else if(x>rr||y<rl)
		return save[index];
	else
	{
		long long mid=(rl+rr)>>1;
		node p=update(x,y,val,rl,mid,2*index);
		node q=update(x,y,val,mid+1,rr,2*index+1);
		save[index].val=p.val+q.val;
		save[index].val+=save[index].reset*(rr-rl+1);
		return save[index];
	}
}

long long query(long long x,long long y,long long rl,long long rr,long long index,long long count)
{
	if(x<=rl&&y>=rr)
		return save[index].val+count*(rr-rl+1);
	else if(x>rr||y<rl)
		return 0;
	else
	{
		long long mid=(rl+rr)>>1;
		count+=save[index].reset;
		long long a=query(x,y,rl,mid,2*index,count);
		long long b=query(x,y,mid+1,rr,2*index+1,count);
		return a+b;
	}	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,q;
		scanf("%lld%lld",&n,&q);
		long long i;
		for(i=0;i<=2*n+4;i++)
			save[i].val=save[i].reset=0;
		while(q--)
		{
			long long type,x,y;
			scanf("%lld%lld%lld",&type,&x,&y);
			if(type==0)
			{
				long long val;
				scanf("%lld",&val);
				update(x,y,val,1,n,1);
	//			for(i=1;i<=2*n+1;i++)
	//				cout<<save[i].val<<" "<<save[i].reset<<endl;
			}
			else
			{
				long long res=query(x,y,1,n,1,0);
				printf("%lld\n",res);
			}
		}
	}
	return 0;
}