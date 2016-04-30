#include<bits/stdc++.h>
using namespace std;

struct node
{
	bool last;
	node *a[10];
};

void insert(node **tree,string val,int i,int len)
{
	if(!*tree)
	{
		*tree=new node;
		int j;
		for(j=0;j<10;j++)
			(*tree)->a[j]=NULL;
		if(i==len)
			(*tree)->last=true;
		else
		{
			(*tree)->last=false;
			insert(&((*tree)->a[val[i]-'0']),val,i+1,len);
		}
	}
	else
	{
		if(i==len)
		{
			(*tree)->last=true;
			return;
		}
		else
			insert(&((*tree)->a[val[i]-'0']),val,i+1,len);
	}
}

bool checkutil(node **tree,string val,int i,int len)
{
	if(!*tree)
		return false;
	if(i==len&&(*tree)->last)
		return true;
	else if(i==len)
		return false;
	else if(i!=len)
		return checkutil(&((*tree)->a[val[i]-'0']),val,i+1,len);
}

bool check(node **tree,string val)
{
	if(checkutil(tree,val,0,val.length()))
		return false;
	insert(tree,val,0,val.length());
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		bool res=true;
		node *tree=new node;
		int n;
		scanf("%d",&n);
		int i;
		tree->last=false;
		for(i=0;i<10;i++)
			tree->a[i]=NULL;
		string a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			if(res&&!check(&tree,a[i]))
				res=false;
		}
		for(i=n-1;i>=0;i--)
		{
			if(!res)
				break;
			if(checkutil(&tree,a[i],0,a[i].length()-1))
				res=false;
		}
		if(res)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}