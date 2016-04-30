#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
char a[50][51];
int save[50][51];

list<pp> lst;

int check(int h,int w,int i,int j,pp st)
{
	if(i<0||j<0||i>=h||j>=w)
		return -1;
	if(a[i][j]==a[st.first][st.second]+1)
		return 1;
	else
		return -1;
}

int bfs(pp st,int h,int w)
{
	int res=save[st.first][st.second];
	if(res!=-1)
		return res;
	int i,j;
	for(i=st.first-1;i<=st.first+1;i++)
	{
		for(j=st.second-1;j<=st.second+1;j++)
		{
			if(check(h,w,i,j,st)!=-1)
			{
				int answer=bfs(pp(i,j),h,w);
				if(answer>save[st.first][st.second])
					save[st.first][st.second]=answer;
			}
		}
	}
	if(save[st.first][st.second]==-1)
		save[st.first][st.second]=a[st.first][st.second]-'A'+1;
	return save[st.first][st.second];
}

/*int bfs(pp st,int h,int w)
{
	int res=1;
	save[st.first][st.second]=1;
	queue<pp> q;
	q.push(st);
	while(!q.empty())
	{
		pp temp=q.front();
		q.pop();
		int i,j;
		for(i=temp.first-1;i<=temp.first+1;i++)
		{
			for(j=temp.second-1;j<=temp.second+1;j++)
			{
				int ans=check(h,w,i,j,temp);
				if(ans>res)
					res=ans;
				if(ans!=-1)
					q.push(pp(i,j));
			}
		}
	}
	return res;
}
*/
int main()
{
	int cases=1;
	while(1)
	{
		lst.clear();
		int h,w;
		scanf("%d%d",&h,&w);
		if(h==0&&w==0)
			break;
		int i,j;
		for(i=0;i<h;i++){
			scanf("%s",a[i]);
			for(j=0;j<w;j++){
				if(a[i][j]=='A')
					lst.push_back(pp(i,j));
				save[i][j]=-1;
			}
		}
		int maxm=0;
		while(!lst.empty())
		{
			int res=bfs(lst.front(),h,w);
			lst.pop_front();
			if(res>maxm)
				maxm=res;
		}
		printf("Case %d: %d\n",cases,maxm);
		cases++;
	}
	return 0;
}