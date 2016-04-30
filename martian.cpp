#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

struct node
{
	int l,r,sl,sr;
};

node save[501][501];
int tt[501][501];

int finding(pp pr)
{
	if(pr.first==0&&pr.second==0)
		return max(save[0][0].l,save[0][0].r);
	else if(pr.first<0||pr.second<0)
		return 0;
	else if(tt[pr.first][pr.second])
		return tt[pr.first][pr.second];
	else
	{
		tt[pr.first][pr.second]=max(save[pr.first][pr.second].sr+finding(pp(pr.first,pr.second-1)),save[pr.first][pr.second].sl+finding(pp(pr.first-1,pr.second)));
		return tt[pr.first][pr.second];
	}
}

int main()
{
	while(1)
	{
		int r,c;
		scanf("%d%d",&r,&c);
		if(r==c&&r==0)
			break;
		int i,j;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				tt[i][j]=0;
				scanf("%d",&save[i][j].l);
				if(j!=0)
					save[i][j].sl=save[i][j-1].sl+save[i][j].l;
				else
					save[i][j].sl=save[i][j].l;
			}
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&save[i][j].r);
				if(i!=0)
					save[i][j].sr=save[i-1][j].sr+save[i][j].r;
				else
					save[i][j].sr=save[i][j].r;
			}
		}
		int res=0;
		pp pr(r-1,c-1);
		int ans=finding(pr);
		printf("%d\n",ans);
	}
	return 0;
}