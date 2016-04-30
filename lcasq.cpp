// <O(n),O(sqrt(n))>

#include<bits/stdc++.h>
using namespace std;

vector<int> *adj; 
int *level,*par,*p;

int bfs(int n)
{
	int c=-1;
	queue<int> q;
	q.push(-1);
	q.push(0);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(temp==-1&&q.empty())
			break;
		if(temp==-1)
			q.push(-1),c++;
		else
		{
			level[temp]=c;
			for(int i=0;i<adj[temp].size();i++)
				q.push(adj[temp][i]);
		}
	}
	return c;
}

int main()
{
	int n;
	scanf("%d",&n);
	adj=new vector<int>[n];
	level=new int[n];
	par=new int[n];
	p=new int[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		int val,m;
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&val);
			adj[i].push_back(val);
			par[val]=i;
		}			
	}	
	int h=bfs(n);
	int nr=sqrt(h);
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int temp=q.front();
		q.pop();
		if(level[temp]<nr)
			p[temp]=0;
		else if(level[temp]%nr==0)
			p[temp]=par[temp];
		else
			p[temp]=p[par[temp]];
		for(int i=0;i<adj[temp].size();i++)
			q.push(adj[temp][i]);
	}
	int query;
	scanf("%d",&query);
	while(query--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		while(p[a]!=p[b])
		{
			if(level[a]>level[b])
				a=p[a];
			else
				b=p[b];
		}
		while(a!=b)
		{
			if(level[a]>level[b])
				a=par[a];
			else
				b=par[b];
		}
		printf("%d\n",a);
	}
	return 0;
}