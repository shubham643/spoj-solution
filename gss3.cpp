#include<bits/stdc++.h>
using namespace std;

struct node
{
	int sum,left,right,ans;
};

node save[10000000];

node combineans(node a,node b)
{
	node temp;
	temp.sum=a.sum+b.sum;
	temp.left=max(a.left,a.sum+b.left);
	temp.right=max(b.right,b.sum+a.right);
	temp.ans=max(a.right+b.left,max(a.ans,b.ans));
	return temp;
}

node construct(int *a,int s,int e,int index)
{
	if(s==e)
	{
		save[index].ans=save[index].sum=save[index].left=save[index].right=a[s];
		return save[index];
	}
	else
	{
		int mid=(s+e)>>1;
		node p=construct(a,s,mid,2*index);
		node q=construct(a,mid+1,e,2*index+1);
		save[index]=combineans(p,q);
		return save[index];
	}
}

node update(int index,int x,int y,int rl,int rr)
{
	if(x>rr){
		node temp={-99999,-99999,-99999,-99999};
		return temp;
	}
	if(x==rl&&x==rr)
	{
		save[index].ans=save[index].left=save[index].right=save[index].sum=y;
		return save[index];
	}
	else
	{
		node p;
		int mid=(rl+rr)>>1;
		if(x<=mid){
			p=update(2*index,x,y,rl,mid);
			save[index]=combineans(p,save[2*index+1]);
		}
		else{
			p=update(2*index+1,x,y,mid+1,rr);
			save[index]=combineans(save[2*index],p);
		}
		return save[index];
	}
}

node findit(int x,int y,int rl,int rr,int index)
{
	if(x<=rl&&y>=rr)
		return save[index];
	else if(x>rr||y<rl){
		node temp={-99999,-99999,-99999,-99999};
		return temp;
	}
	else
	{
		int mid=(rl+rr)>>1;
		node p=findit(x,y,rl,mid,2*index);
		node q=findit(x,y,mid+1,rr,2*index+1);
		return combineans(p,q);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,a[n+1];
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	construct(a,1,n,1);
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==0)
		{
			int prev=a[x];
			a[x]=y;
			update(1,x,y,1,n);
		}
		else
		{
			node res=findit(x,y,1,n,1);
			printf("%d\n",res.ans);
		}
	}
	return 0;
}