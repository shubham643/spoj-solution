#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
struct node
{
	int d,len,coins;
};

int dis[101][10001];

class cmp
{
public:
	bool operator()(node a,node b)
	{
		return a.len<b.len;
	}
};

int bfs(vector<node> *graph,int n,int k)
{
	multiset<node,cmp>::iterator temp;
	multiset<node,cmp> q;
	q.insert(node{1,0,0});
	while(!q.empty())
	{
		temp=q.begin();
		vector<node>::iterator ii;
		for(ii=graph[temp->d].begin();ii!=graph[temp->d].end();ii++)
		{
			if(temp->coins+ii->coins<=k && dis[ii->d][temp->coins+ii->coins] > temp->len+ii->len)
			{
				dis[ii->d][temp->coins+ii->coins]=temp->len+ii->len;
				q.insert(node{ii->d,temp->len+ii->len,temp->coins+ii->coins});
			}
		}
		q.erase(temp);
	}
	int minm=dis[n][0];
	for(int i=1;i<=k;i++)
	{
		if(dis[n][i]<minm)
			minm=dis[n][i];
	}
	return minm;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,n,r;
		scanf("%d%d%d",&k,&n,&r);
		int i;
		for(i=1;i<=n;i++){
			for(int j=0;j<=k;j++)
				dis[i][j]=INT_MAX;
		}
		vector<node> graph[n+1];
		for(i=0;i<r;i++)
		{
			int s,d,l,coins;
			scanf("%d%d%d%d",&s,&d,&l,&coins);
			graph[s].push_back(node{d,l,coins});
		}
		dis[1][0]=0;
		int res=bfs(graph,n,k);
		if(res==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",res);
	}
	return 0;
}