#include<bits/stdc++.h>
using namespace std;

struct node
{
	int name,h;
};

int main()
{
	int t,kk;
	scanf("%d",&t);
	for(kk=1;kk<=t;kk++)
	{
		int n;
		scanf("%d",&n);
		vector<int> v[n+1];
		int par[n+1];
		int height[n+1];
		bool flag[n+1];
		int i,j;
		for(i=1;i<=n;i++)
			flag[i]=false;
		for(i=1;i<=n;i++)
		{
			int m;
			scanf("%d",&m);
			while(m--)
			{
				int e;
				scanf("%d",&e);
				v[i].push_back(e);
				flag[e]=true;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
				break;
		}
		par[i]=i;
		height[i]=0;
		node temp;
		temp.h=0;
		temp.name=i;
		queue<node> q;
		q.push(temp);
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			height[temp.name]=temp.h;
			vector<int>::iterator ii;
			for(ii=v[temp.name].begin();ii!=v[temp.name].end();ii++)
			{
				node tt;
				tt.h=temp.h+1;
				tt.name=*ii;
				q.push(tt);
				par[*ii]=temp.name;
			}
		}
		int query;
		scanf("%d",&query);
		printf("Case %d:\n",kk);
		while(query--)
		{
			int st,en;
			scanf("%d%d",&st,&en);
			int h1=height[st],h2=height[en];
			{
				while(h1>h2){
					h1--;
					st=par[st];
				}
				while(h2>h1)
				{
					h2--;
					en=par[en];
				}
			}
			while(st!=en)
			{
				st=par[st];
				en=par[en];
			}
			printf("%d\n",st);
		}
	}
	return 0;
}