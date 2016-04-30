#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

bool flag[10009];

vector<int> v[10000];

void makegraph()
{
	int i,j,k;
	for(i=1001;i<10000;i++)
	{
		if(flag[i])
			continue;
		int dig,res,strt;
		dig=i/1000; res=i%1000;
		for(j=1;j<10;j++)
		{
			if(j==dig)
				continue;
			if(!flag[j*1000+res])
				v[i].push_back(j*1000+res);
		}
		dig=i/100; dig%=10; res=i%100; strt=i/1000*1000; 
		for(j=0;j<10;j++)
		{
			if(j==dig)
				continue;
			if(!flag[strt+j*100+res])
				v[i].push_back(strt+j*100+res);
		}
		dig=i/10; dig%=10; res=i%10; strt=i/100*100; 
		for(j=0;j<10;j++)
		{
			if(j==dig)
				continue;
			if(!flag[strt+j*10+res])
				v[i].push_back(strt+j*10+res);
		}
		dig=i%10; strt=i/10*10; 
		for(j=0;j<10;j++)
		{
			if(j==dig)
				continue;
			if(!flag[strt+j])
				v[i].push_back(strt+j);
		}
	}
}

void compute()
{
	int i,j;
	for(i=2;i<=100;i++)
	{
		if(!flag[i])
		{
			for(j=i*i;j<10000;j+=i)
				flag[j]=true;
		}
	}
	makegraph();
}

int bfs(int x,int y)
{
	queue<pp> q;
	q.push(pp(x,0));
	bool check[10000];
	int i;
	for(i=1000;i<10000;i++)
		check[i]=false;
	vector<int>::iterator ii;
	while(!q.empty())
	{
		pp temp=q.front();
		q.pop();
		for(ii=v[temp.first].begin();ii!=v[temp.first].end();ii++)
		{
			if(check[*ii])
				continue;
			if(*ii==y)
				return temp.second+1;
			check[*ii]=true;
			q.push(pp(*ii,temp.second+1));
		}
	}
	return -1;
}

int main()
{
	compute();
	int t;
	scanf("%d",&t);
	int i;
/*	for(i=1000;i<10000;i++)
	{
		if(flag[i])
			continue;
		cout<<i<<": ";
		vector<int>::iterator ii;
		for(ii=v[i].begin();ii!=v[i].end();ii++)
			cout<<*ii<<" ";
		cout<<endl;
	}
*/	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
		{
			printf("0\n");
			continue;
		}
		int res=bfs(x,y);
		if(res==-1)
			printf("Impossible\n");
		else
			printf("%d\n",res);
	}
	return 0;
}