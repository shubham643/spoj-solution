#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val,reset;
};

node save[10000000];

node construct(int s,int e,int index)
{
	if(s==e)
	{
		save[index].val=0;
		save[index].reset=0;
		return save[index];
	}	
	else
	{
		int mid=(s+e)>>1;
		node p=construct(s,mid,2*index);
		node q=construct(mid+1,e,2*index+1);
		save[index].val=save[index].reset=0;
		return save[index];
	}
}

node update(int x,int y,int index,int rl,int rr)
{
	if(x<=rl&&y>=rr)
	{
		save[index].reset++;
		save[index].val=rr-rl+1-save[index].val;
		return save[index];
	}
	else if(x>rr||y<rl){
		return save[index];
	}
	else
	{
		int mid=(rl+rr)>>1;
		node p=update(x,y,2*index,rl,mid);
		node q=update(x,y,2*index+1,mid+1,rr);
		save[index].val=p.val+q.val;
		if(save[index].reset&1)
			save[index].val=rr-rl+1-save[index].val;
		return save[index];
	}
}

int query(int x,int y,int index,int rl,int rr,int count)
{
	if(x<=rl&&y>=rr)
	{
		int res;
		if(count&1)
			res=rr-rl+1-save[index].val;
		else
			res=save[index].val;
		return res;
	}
	else if(x>rr||y<rl)
		return 0;
	else
	{
		int mid=(rl+rr)>>1;
		count+=save[index].reset;
		int p=query(x,y,2*index,rl,mid,count);
		int q=query(x,y,2*index+1,mid+1,rr,count);
		return p+q;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
//	construct(1,n,1);             
	node temp;
	temp.val=temp.reset=0;
	int i;
	for(i=1;i<=n;i++)
		save[i].val=save[i].reset=save[2*i].val=save[2*i].reset=save[2*i+1].val=save[2*i+1].reset=0;
	while(m--)
	{
		int type,x,y;
		scanf("%d%d%d",&type,&x,&y);
		if(type==0)
			update(x,y,1,1,n);
		else
		{
			int p=query(x,y,1,1,n,0);
			printf("%d\n",p);
		}
	}
	return 0;
}