#include<bits/stdc++.h>
using namespace std;

bool flag[50000];

struct node
{
	int count,ver;
};

int main()
{
	int v;
	scanf("%d",&v);
	int i,a,b;
	multimap<int,int> m;
	for(i=0;i<v-1;i++)
	{
		scanf("%d%d",&a,&b);
		m.insert(pair<int,int>(a,b));
		m.insert(pair<int,int>(b,a));
	}
	queue<node> q;
	int ekdamlast;
	pair<multimap<int,int>::iterator,multimap<int,int>::iterator> pr;
	multimap<int,int>::iterator ii;
	node temp,temp2;
	temp.count=0;
	temp.ver=1;
	q.push(temp);
	int maxm=0;
	while(!q.empty())
	{
		temp=q.front();
		if(temp.count>maxm)
			maxm=temp.count;
		pr=m.equal_range(temp.ver);
		flag[temp.ver]=true;
		if(pr.first!=m.end())
		{
			for(ii=pr.first;ii!=pr.second;ii++)
			{
				if(flag[ii->second])
					continue;
				temp2.ver=ii->second;
				temp2.count=temp.count+1;
				q.push(temp2);
			}
		}
		q.pop();
		ekdamlast=temp.ver;
	}
	for(i=0;i<=v;i++)
		flag[i]=false;
	temp.ver=ekdamlast;
	temp.count=0;
	q.push(temp);
	maxm=0;
	while(!q.empty())
	{
		temp=q.front();
		if(temp.count>maxm)
			maxm=temp.count;
		pr=m.equal_range(temp.ver);
		flag[temp.ver]=true;
		if(pr.first!=m.end())
		{
			for(ii=pr.first;ii!=pr.second;ii++)
			{
				if(flag[ii->second])
					continue;
				temp2.ver=ii->second;
				temp2.count=temp.count+1;
				q.push(temp2);
			}
		}
		q.pop();
		ekdamlast=temp.ver;
	}
	printf("%d",maxm);
	return 0;
}
