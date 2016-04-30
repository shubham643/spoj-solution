#include<bits/stdc++.h>
using namespace std;

struct node
{
	int d,wt;
};

class Graph
{
	public:
		int v;
		vector<node> *adj;
		Graph(int v)
		{
			this->v=v;
			adj=new vector<node>[v+1];
		}
		void add_node(int s,int d,int wt)
		{
			node temp;
			temp.d=d;
			temp.wt=wt;
			adj[s].push_back(temp);
		}
		int dijktra(int s,int d)
		{
			bool flag[v+1];
			int dis[v+1];
			int i;
			for(i=0;i<=v;i++)
			{
				flag[i]=false;
				dis[i]=999999999;
			}
			flag[s]=true;
			dis[s]=0;
			int minm=s;
			while(!flag[d])
			{
				flag[minm]=true;
				if(minm==d)
					break;
				vector<node>::iterator ii,jj;
				int tempmin=999999999,savedminm=minm;
				for(ii=adj[minm].begin();ii!=adj[minm].end();ii++)
				{
					if(flag[ii->d])
						continue;
					int tempo=dis[minm]+ii->wt;
					dis[ii->d]=min(tempo,dis[ii->d]);
					if(dis[ii->d]<tempmin)
					{
						tempmin=dis[ii->d];
						savedminm=ii->d;
					}
				}
				minm=savedminm;
			}
			return dis[d];
		}
};

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		Graph mygraph(n);
		map<string,int> mymap;
		int i;
		for(i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			mymap[s]=i;
			int p;
			scanf("%d",&p);
			int j;
			for(j=0;j<p;j++)
			{
				int d,c;
				scanf("%d%d",&d,&c);
				mygraph.add_node(i,d,c);
			}
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			string a,b;
			cin>>a;
			cin>>b;
			int in1=mymap[a];
			int in2=mymap[b];
			int res=mygraph.dijktra(in1,in2);
			printf("%d\n",res);
		}
	}
	return 0;
}