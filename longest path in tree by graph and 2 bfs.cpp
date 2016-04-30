#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;

int ekdamlast;

class Graph
{
    int v,e;
    list<int> *adj;
    public:
    Graph(int p,int q)
    {
        v=p;
        e=q;
        adj=new list<int>[v+1];
    }
    void add_node(int s,int e)
    {
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    int find_maxlen(int start);
    int findutil(int i,bool *check);
};

int Graph::find_maxlen(int start)
{
    int i,val,max=-1;
    bool check[v+1];
    for(i=0;i<=v;i++)
        check[i]=false;
    val=findutil(start,check);
    if(val>max)
        max=val;
    return max;
}

int Graph::findutil(int i,bool *check)
{
    ekdamlast=i;
    int val,max=0;
    list<int>::iterator ii;
    check[i]=true;
    for(ii=adj[i].begin();ii!=adj[i].end();ii++)
    {
        if(!check[*ii])
        {
            val=1+findutil(*ii,check);
            if(val>max)
            {
                max=val;
            }
        }
    }
    return max;
}


int main()
{
    int n;
    scanf("%d",&n);
    Graph mygraph(n,n-1);
    int i;
    for(i=0;i<n-1;i++)
    {
        int s,e;
        scanf("%d%d",&s,&e);
        mygraph.add_node(s,e);
    }
    int res=mygraph.find_maxlen(1);
    res=mygraph.find_maxlen(ekdamlast);
    printf("%d",res);
    return 0;
}

