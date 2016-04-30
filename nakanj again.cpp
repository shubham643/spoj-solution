#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

struct node
{
	pp loc;
	int step;
};

int save[8][8];

bool check(int x,int y)
{
	if(x<0||y<0||x>=8||y>=8)
		return false;
	return true;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j;
		char s[3],d[3];
		scanf("%s%s",s,d);
		pp st,des;
		st=pp(s[1]-'0'-8,s[0]-'a');
		st.first=-st.first;
		des=pp(d[1]-'0'-8,d[0]-'a');
		des.first=-des.first;
		if(st==des)
		{
			printf("0\n");
			continue;
		}
		for(i=0;i<8;i++)
			for(j=0;j<8;j++)
				save[i][j]=100;
		save[st.first][st.second]=0;
		int answer=0;
		queue<node> q;
		q.push(node{st,0});
		while(!q.empty())
		{
			node temp=q.front();
			q.pop();
			if(temp.loc.first==des.first&&temp.loc.second==des.second){
				answer=temp.step+1;
				save[des.first][des.second]=temp.step+1;
				break;
			}
			for(i=-2;i<=2;i++)
			{
				for(j=-2;j<=2;j++)
				{
					if(i==j||-i==j)
						continue;
					if(i<=1&&i>=-1&&j<=1&&j>=-1)
						continue;
					if(i==0||j==0)
						continue;
					int x=temp.loc.first+i;
					int y=temp.loc.second+j;
					if(check(x,y))
					{
						if(x==des.first&&y==des.second)
						{
							answer=temp.step+1;
							save[x][y]=answer;
							goto end;
						}
						if(save[x][y]==100)
						{
							save[x][y]=temp.step+1;
							q.push(node{pp(x,y),temp.step+1});
						}
					}
				}
			}
		}
	end:
		printf("%d\n",answer);
	}
	return 0;
}