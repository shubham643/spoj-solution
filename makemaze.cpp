#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

char s[25][25];

bool bfs(int fi,int fj,int si,int sj,int m,int n)
{
//	cout<<fi<<fj<<si<<sj;
	queue<pp> q;
	bool flag[m+1][n+1];
	q.push(pp(fi,fj));
	int i,j;
	for(i=0;i<=m;i++)
		for(j=0;j<=n;j++)
			flag[i][j]=false;
	flag[fi][fj]=true;
	while(!q.empty()&&!flag[si][sj])
	{
		pp temp=q.front();
		q.pop();
		if(temp.first+1<m&&!flag[temp.first+1][temp.second]&&s[temp.first+1][temp.second]=='.')
		{
			q.push(pp(temp.first+1,temp.second));
			flag[temp.first+1][temp.second]=true;
		}
		if(temp.first-1>=0&&!flag[temp.first-1][temp.second]&&s[temp.first-1][temp.second]=='.')
		{
			q.push(pp(temp.first-1,temp.second));
			flag[temp.first-1][temp.second]=true;
		}
		if(temp.second+1<n&&!flag[temp.first][temp.second+1]&&s[temp.first][temp.second+1]=='.')
		{
			q.push(pp(temp.first,temp.second+1));
			flag[temp.first][temp.second+1]=true;
		}
		if(temp.second-1>=0&&!flag[temp.first][temp.second-1]&&s[temp.first][temp.second-1]=='.')
		{
			q.push(pp(temp.first,temp.second-1));
			flag[temp.first][temp.second-1]=true;
		}
	}
	if(flag[si][sj])
		return true;
	else
		return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		int i;
		for(i=0;i<m;i++)
			scanf("%s",s[i]);
		int fi=-1,fj=-1,si=-1,sj=-1;
		int count=0;
		for(i=0;i<n;i++)
		{
			if(s[0][i]=='.')
			{
				count++;
				if(fi==-1)
				{
					fi=0; fj=i;
				}
				else
				{
					si=0;sj=i;
				}
			}
			if(s[m-1][i]=='.'&&m!=1)
			{
				count++;
				if(fi==-1)
				{
					fi=m-1; fj=i;
				}
				else
				{
					si=m-1;sj=i;
				}
			}
		}
		for(i=1;i<m-1;i++)
		{
			if(s[i][0]=='.')
			{
				count++;
				if(fi==-1)
				{
					fi=i; fj=0;
				}
				else
				{
					si=i;sj=0;
				}
			}
			if(s[i][n-1]=='.'&&n!=1)
			{
				count++;
				if(fi==-1)
				{
					fi=i; fj=n-1;
				}
				else
				{
					si=i;sj=n-1;
				}
			}
		}
		if(count!=2)
		{
			printf("invalid\n");
			continue;
		}
		bool res=bfs(fi,fj,si,sj,m,n);
		if(res)
			printf("valid\n");
		else
			printf("invalid\n");
	//	cout<<"theek se";
	}
	return 0;
}