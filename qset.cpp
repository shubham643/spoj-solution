#include<bits/stdc++.h>
using namespace std;

struct node
{
	int cnt,tot;
	int left[3],right[3];
	node()
	{
		cnt=tot=0;
		int i;
		for(i=0;i<3;i++)
			left[i]=right[i]=0;
	}
};

node *a;

node merge(int index)
{
	a[index].tot=(a[index*2].tot+a[index*2+1].tot)%3;
	a[index].cnt=a[index*2].cnt+a[index*2+1].cnt;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(i+j%3==0)
				a[index].cnt+=a[2*index].right[i]*a[2*index+1].left[j];
	for(int i=0;i<3;i++){
		a[index].left[i]=a[2*index].left[i]+a[2*index+1].left[(6-a[2*index].tot+i)%3];
		a[index].right[i]=a[2*index+1].right[i]+a[2*index].right[(6-a[2*index+1].tot+i)%3];
	}
	return a[index];
}

node assign(int index,int p)
{
	a[index]=node();
	int tot=p;
	a[index].tot=tot;
	a[index].left[tot]=a[index].right[tot]=1;	
	if(tot==0)
		a[index].cnt=1;
	return a[index];
}

void construct(char *s,int st,int en,int index)
{
	if(st==en)
	{
		int tot=(s[st]-'0')%3;
		a[index]=assign(index,tot);
		return;
	}
	else
	{
		int mid=(st+en)>>1;
		construct(s,st,mid,index*2);
		construct(s,mid+1,en,index*2+1);
		a[index]=merge(index);
	}
}

void update(int x,char val,int s,int e,int index)
{
	if(x<s||x>e)
		return;
	if(s==e&&x==s)
	{
		assign(index,(val-'0')%3);
		return;
	}
	int mid=(s+e)>>1;
	update(x,val,s,mid,index*2);
	update(x,val,mid+1,e,index*2+1);
	a[index]=merge(index);
}

node query(int x,int y,int s,int e,int index)
{
	if(x>y||x>e||y<s)
	{
		node temp;
		return temp;
	}
	if(x<=s&&y>=e)
		return a[index];
	node p=query(x,y,s,(s+e)>>1,index*2);
	node q=query(x,y,s,(s+e)>>1,index*2);
	a[index]=merge(index);
	return a[index];
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char s[n+1];
	scanf("%s",s);
	int size=ceil(log2(n));
	size=2*(pow(2,size));
	a=new node[size];
	construct(s,0,n-1,1);
	while(m--)
	{
		int type,x;
		scanf("%d%d",&type,&x);
		if(type==1){
			char y;
			scanf("%c",&y);
			update(x,y,1,n,1);
		}
		else{
			int y;
			scanf("%d",&y);
			printf("%d\n",query(x,y,1,n,1).cnt);
		}
	}
}