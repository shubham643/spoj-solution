#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

struct node
{
	int d,wt;
};

class cmp
{
public:
	bool operator()(const pp &a,const pp &b)
	{
		return a.second<b.second;
	}
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
			int dis[v+1];
			int i;
			for(i=0;i<=v;i++)
				dis[i]=1000000000;
			dis[s]=0;
			set<pp> mymultiset;
			vector<node>::iterator jj;
			set<pp,cmp>::iterator ii,kk,check;
			set.insert(pp(0,s));
			while(!set.empty())
			{
				ii=set.begin();
	//			if(ii->first==d)
	//				break;
				for(jj=adj[ii->second].begin();jj!=adj[ii->second].end();jj++)
				{
					if(dis[jj->d]>dis[ii->second]+jj->wt)
					{
						if(dis[jj->d]!=1000000000)
							set.erase(set.find(pp(jj->d,dis[jj->d])));
						dis[jj->d]=dis[ii->second]+jj->wt;
						set.insert(pp(jj->d,dis[ii->second]+jj->wt));
					}
				}
				set.erase(ii);
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
			char s[20];
			scanf("%s",s);
			string str=s;
			mymap[str]=i;
	//		cout<<mymap[s];
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
			char a[20],b[20];
			scanf("%s%s",a,b);
			string str1=a,str2=b;
			int in1=mymap[str1];
			int in2=mymap[str2];
			int res=mygraph.dijktra(in1,in2);
	
			printf("%d\n",res);
		}
	}
	return 0;
}