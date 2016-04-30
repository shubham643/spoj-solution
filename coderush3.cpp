#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[9000000];

void construct(int *arr,int index,int s,int e)
{
	if(s>e)
		return;
	if(s==e)
	{
		a[index].first=arr[s-1];
		a[index].second=0;
		return;
	}
	int mid=(s+e)>>1;
	construct(arr,index*2,s,mid);
	construct(arr,index*2 +1,mid+1,e);
	a[index].first=a[index*2].first + a[index*2 +1].first;
	a[index].second=0;
}

void update(int p,int q,int s,int e,int index,int v)
{
	if(p>e||q<s)
		return;
	if(p<=s&&e<=q)
	{
		a[index].second^=v;;
		if((e-s+1)%2==1)
			a[index].first^=v;
	}
	else
	{
		int mid=(s+e)>>1;
		update(p,q,s,mid,index*2,v);
		update(p,q,mid+1,e,index*2+1,v);
		a[index].first=a[index*2].first+a[index*2+1].first;
	}
}

int query(int p,int q,int s,int e,int index,int till)
{
	if(p>e||q<s)
		return 0;
	if(p<=s&&q>=e){
		if((e-s+1)%2==1){
			int val=a[index].first^till;
			return val;
		}
		else
			return a[index].first;
	}
	else
	{
		int mid=(s+e)>>1;
		return query(p,q,s,mid,index*2,till^(a[index].second))+query(p,q,mid+1,e,index*2+1,till^(a[index].second));
	}
}

int main()
{
	int val=4^3;
	val+=10^3;
	int vala=17^3;
	cout<<vala<<" "<<val;
	{
		int n;
		int arr[n];
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		int q;
		construct(arr,1,1,n);
			for(int i=1;a[i].first!=0;i++)
					cout<<a[i].first<<" ";
				cout<<endl;
			
		scanf("%d",&q);
		while(q--)
		{
			int type;
			scanf("%d",&type);
			if(type==1)
			{
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%d\n",query(l,r,1,n,1,0));
			}
			else
			{
				int l,r,x;
				scanf("%d%d%d",&l,&r,&x);
				update(l,r,1,n,1,x);
				for(int i=1;a[i].first!=0;i++)
					cout<<a[i].first<<" ";
				cout<<endl;
			}
		}
	}
}