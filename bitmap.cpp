#include<bits/stdc++.h>
using namespace std;

void bfs(string *s,int n,int m,queue<pair<int,int> > q)
{
	int dis[n][m];
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(s[i][j]=='1'){
				q.push(pair<int,int>(i,j));
				dis[i][j]=0;
			}
			else
				dis[i][j]=99999;
		}
	}
	while(!q.empty())
	{
		pair<int,int> pr=q.front();
		q.pop();
		if(pr.first+1<n&&dis[pr.first+1][pr.second]>dis[pr.first][pr.second]+1)
		{
			dis[pr.first+1][pr.second]=dis[pr.first][pr.second]+1;
			q.push(pair<int,int>(pr.first+1,pr.second));	
		}
		if(pr.first-1>=0&&dis[pr.first-1][pr.second]>dis[pr.first][pr.second]+1)
		{
			dis[pr.first-1][pr.second]=dis[pr.first][pr.second]+1;
			q.push(pair<int,int>(pr.first-1,pr.second));	
		}
		if(pr.second+1<m&&dis[pr.first][pr.second+1]>dis[pr.first][pr.second]+1)
		{
			dis[pr.first][pr.second+1]=dis[pr.first][pr.second]+1;
			q.push(pair<int,int>(pr.first,pr.second+1));	
		}
		if(pr.second-1>=0&&dis[pr.first][pr.second-1]>dis[pr.first][pr.second]+1)
		{
			dis[pr.first][pr.second-1]=dis[pr.first][pr.second]+1;
			q.push(pair<int,int>(pr.first,pr.second-1));	
		}
	}
	for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%d ",dis[i][j]);
			printf("\n");
		}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		queue<pair<int,int> > q;
		string s[n];
		int i;
		for(i=0;i<n;i++){
			cin>>s[i];
		}
		bfs(s,n,m,q);
	}
	return 0;
}