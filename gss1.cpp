#include<bits/stdc++.h>
using namespace std;

struct node
{
	int ans,sum,left,right;
};

node save[10000000];

node combine(node a,node b)
{
	node temp;
	temp.sum=a.sum+b.sum;
	temp.left=max(a.sum+b.left,a.left);
	temp.right=max(b.sum+a.right,b.right);
	temp.ans=max(max(a.ans,b.ans),a.right+b.left);
	return temp;
}

void construct(int *a,int s,int e,int index)
{
	if(s==e){
		save[index].sum=a[s];
		save[index].ans=a[s];
		save[index].left=a[s];
		save[index].right=a[s];
	}
	else
	{
		int mid=(s+e);
		mid=mid>>1;
		construct(a,s,mid,2*index);
		construct(a,mid+1,e,2*index+1);
		save[index]=combine(save[2*index],save[2*index+1]);
	}
}

node findit(int x,int y,int index,int rl,int rr)
{
	if(x<=rl&&y>=rr){
		return save[index];
	}
	else if(x>rr||y<rl)
	{
		node temp;
		temp.sum=temp.ans=temp.left=temp.right=-99999;
		return temp;
	}
	else
	{
		int res;
		node p=findit(x,y,index*2,rl,(rl+rr)/2);
		node q=findit(x,y,index*2+1,(rl+rr)/2+1,rr);
		return combine(p,q);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n+1];
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	construct(a,1,n,1);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		node res=findit(x,y,1,1,n);
	//	cout<<res.ans<<" "<<res.sum<<" ";
		printf("%d\n",res.ans);
	}
	return 0;
}