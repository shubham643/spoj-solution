#include<bits/stdc++.h>
using namespace std;

class Graph
{
	public:
	int n,k;
	int *save;
	vector<int> *adj;
	Graph(int n,int k)
	{
		this->n=n+1;
		this->k=k;
		adj=new vector<int>[n+1]; 
		save=new int[n+1];
		int i;
		for(i=0;i<=n;i++)
			save[i]=0;
	}
	void add_node(int s,int e)
	{
		adj[s].push_back(e);
		adj[e].push_back(s);
	}
	bool bfs(int s)
	{
		bool res=true;
		int i;
		if(save[s])
			return true;
		save[s]=1;
		int temp;
		queue<int> q;
		vector<int>::iterator ii;
		q.push(s);
		while(!q.empty())
		{
			temp=q.front();
			int sex=save[temp];
			for(ii=adj[temp].begin();ii!=adj[temp].end();ii++)
			{
				if(save[*ii]==sex)
				{
					res=false;
					goto ending;
				}
				else if(!save[*ii])
				{
					if(sex==1)
						save[*ii]=2;
					else
						save[*ii]=1;
					q.push(*ii);
				}
			}
			q.pop();
		}
	ending: 
		return res;
	}
};

int main()
{
	int t,j;
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
		int n,k,i;
		scanf("%d%d",&n,&k);
		Graph mygraph(n,k);
		for(i=0;i<k;i++)
		{
			int s,e;
			scanf("%d%d",&s,&e);
			mygraph.add_node(s,e);
		}
		bool answer=true;
		for(i=1;i<=n;i++)
		{
			if(!mygraph.bfs(i))
			{
				printf("Scenario #%d:\nSuspicious bugs found!\n",j);
				answer=false;
				break;
			}
		}
		if(answer)
			printf("Scenario #%d:\nNo suspicious bugs found!\n",j);
	}
	return 0;
}