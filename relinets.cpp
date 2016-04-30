#include<bits/stdc++.h>
using namespace std;

struct node
{
	int ver,wt;
};

class Graph{
	public:
	int v,e;
	vector<node> *adj;
	Graph(int a,int b)
	{
		v=a;
		e=b;
		adj=new vector<node>[a];
	}
	void add_node(int a,int b,int c)
	{
		node temp;
		temp.wt=c;
		temp.ver=b;
		adj[a].push_back(temp);
		temp.ver=a;
		adj[b].push_back(temp);
	}
	void show()
	{
		int i;
		std::vector<node>::iterator ii;
		for(i=1;i<v;i++)
		{
			for(ii=adj[i].begin();ii!=adj[i].end();ii++)
				cout<<ii->ver<<ii->wt<<endl;
		}
	}
	int dfsutil(int val,bool flag,bool *rec,int par)
	{
//		cout<<val<<"  ";
		if(val==1&&flag)
			return 0;
//		if(save[val]!=99999999)
//			return save[val];
		if(rec[val])
			return 99999999;
		rec[val]=true;
		int tempsave=99999999;
		vector<node>::iterator ii;
		for(ii=adj[val].begin();ii!=adj[val].end();ii++)
		{
			if(ii->ver==par)
				continue;
			int temp=ii->wt+dfsutil(ii->ver,true,rec,par);
			if(temp<tempsave)
				tempsave=temp;
	//		cout<<temp<<" ";
		}
//		save[val]=tempsave;
		rec[val]=false;
		return tempsave;
	}
	int dfs()
	{
		int i;
		bool rec[v];
		for(i=0;i<v;i++){
			rec[i]=false;
//			save[i]=99999999;
		}
		int res=dfsutil(1,false,rec,-1);
//		cout<<endl;
//		for(i=1;i<v;i++){
//			cout<<save[i]<<" ";
//		}
//		cout<<endl;
		return res;
	}
};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	Graph mygraph(n+1,m);
	for(i=0;i<m;i++)
	{
		int s,e,wt;
		scanf("%d%d%d",&s,&e,&wt);
		mygraph.add_node(s,e,wt);
	}
//	mygraph.show();
	int res=mygraph.dfs();
	printf("%d\n",res);
}