// <O(nlogn),O(logn)>

#include<bits/stdc++.h>
using namespace std;

vector<int> *adj; 
int *level,*par;

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
	par[0]=0;
	int h=bfs(n);

	int p[n][int(log2(n))];
	for(i=0;i<n;i++)
		for(j=0;(1<<j)<n;j++)
			p[i][j]=-1;
	for(i=0;i<n;i++)
		p[i][0]=par[i];
	for(i=1;(1<<i)<n;i++)
		for(j=0;j<n;j++)
			if(p[j][i-1]!=-1)
				p[j][i]=p[p[j][i-1]][i-1];

	int query;
	scanf("%d",&query);
	while(query--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(level[a]<level[b])
		{
			int temp=a;
			a=b;
			b=temp;
		}
		for(i=1;(1<<i)<=level[a];i++);

		i--;
		for(j=i;j>=0;j--)
		{
			if(level[a]-(1<<j)>=level[b])
				a=p[a][j];
		}
		if(a==b){
			printf("%d\n",a);
		    continue;
		}
		for(j=i;j>=0;j--)
			if(p[a][j]!=-1&&p[a][j]!=p[b][j])
				a=p[a][j], b=p[b][j];
		printf("%d\n",par[a]);
	}
}
