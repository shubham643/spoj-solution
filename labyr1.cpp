#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

struct node
{
	pp loc;
	int count;
};

char save[1000][1001];
bool flag[1000][1000];
int r,c;
list<pp> lst;

void bfs(queue<node> q,pp *maxm,int *res,queue<pp> *extra)
{
	while(!q.empty())
	{
		node temp=q.front();
		q.pop();
		if(flag[temp.loc.first][temp.loc.second])
			continue;
		if(temp.count>*res){
			*res=temp.count;
			(*maxm).first=temp.loc.first;
			(*maxm).second=temp.loc.second;
		}
		flag[temp.loc.first][temp.loc.second]=true;
		if(temp.loc.second>0&&save[temp.loc.first][temp.loc.second-1]=='.'){
			q.push({pp(temp.loc.first,temp.loc.second -1),temp.count+1});
			(*extra).push(pp(temp.loc.first,temp.loc.second -1));
		}
		
		if(temp.loc.second<c-1&&save[temp.loc.first][temp.loc.second+1]=='.'){
			q.push({pp(temp.loc.first,temp.loc.second +1),temp.count+1});
			(*extra).push(pp(temp.loc.first,temp.loc.second +1));
		}

		if(temp.loc.first>0&&save[temp.loc.first-1][temp.loc.second]=='.'){
			q.push({pp(temp.loc.first-1,temp.loc.second),temp.count+1});
			(*extra).push(pp(temp.loc.first-1,temp.loc.second));
		}

		if(temp.loc.first<r-1&&save[temp.loc.first+1][temp.loc.second]=='.'){
			q.push({pp(temp.loc.first+1,temp.loc.second),temp.count+1});
			(*extra).push(pp(temp.loc.first+1,temp.loc.second));
		}
	}
}

void bfs(queue<node> q,pp *maxm,int *res)
{
	while(!q.empty())
	{
		node temp=q.front();
		q.pop();
		if(flag[temp.loc.first][temp.loc.second])
			continue;
		if(temp.count>*res){
			*res=temp.count;
			(*maxm).first=temp.loc.first;
			(*maxm).second=temp.loc.second;
		}
		flag[temp.loc.first][temp.loc.second]=true;
		if(temp.loc.second>0&&save[temp.loc.first][temp.loc.second-1]=='.'){
			q.push({pp(temp.loc.first,temp.loc.second -1),temp.count+1});
		}
		
		if(temp.loc.second<c-1&&save[temp.loc.first][temp.loc.second+1]=='.'){
			q.push({pp(temp.loc.first,temp.loc.second +1),temp.count+1});
		}

		if(temp.loc.first>0&&save[temp.loc.first-1][temp.loc.second]=='.'){
			q.push({pp(temp.loc.first-1,temp.loc.second),temp.count+1});
		}

		if(temp.loc.first<r-1&&save[temp.loc.first+1][temp.loc.second]=='.'){
			q.push({pp(temp.loc.first+1,temp.loc.second),temp.count+1});
		}
	}
}


int detect(pp pr)
{
	pp maxm=pr;
	queue<node> q;
	queue<pp> extra;
	int res=0;
	q.push({pr,0});
	extra.push(pr);
	bfs(q,&maxm,&res,&extra);
	int i,j;
	while(!extra.empty())
	{
	//	cout<<"haee";
		pp tt=extra.front();
		extra.pop();
		flag[tt.first][tt.second]=false;
	}
	flag[pr.first][pr.second]=false;
	q.pop();
	q.push({maxm,0});
	bfs(q,&maxm,&res);
	return res;
}

int findit(int r,int c)
{
	int res=0;
	while(!lst.empty())
	{
		pp pr=lst.front();
		lst.pop_front();
		if(flag[pr.first][pr.second])
			continue;
		else
		{
			int temp=detect(pr);
			if(temp>res)
				res=temp;
		}
	}
	return res;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		lst.clear();
		scanf("%d%d",&c,&r);
		int i,j;
		for(i=0;i<r;i++)
		{
			scanf("%s",save[i]);
			for(j=0;j<c;j++)
			{
				flag[i][j]=false;
				if(save[i][j]=='.')
					lst.push_back(pp(i,j));
			}
		}
		int res=findit(r,c);
		cout<<"Maximum rope length is "<<res<<"."<<endl;
	}
}