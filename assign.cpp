#include<bits/stdc++.h>
using namespace std;

int save[21][21];
int ans[21][21][21];

int findit(int c,int n,int *flag)
{
	if(c>n)
		return 1;
	int i,res=0,k;
	for(i=1;i<=n;i++)
	{
		if(!flag[i]&&save[i][c])
		{
			for(k=1;k<=n;k++){
				if(ans[c][i][k]!=flag[k])
					break;
			}
			if(k==n+1&&ans[c][i][0])
				res+=ans[c][i][0];
			else
			{
				flag[i]=1;
				for(k=1;k<=n;k++)
					ans[c][i][k]=flag[k];
				ans[c][i][0]=findit(c+1,n,flag);
				res+=ans[c][i][0];
				flag[i]=0;
				ans[c][i][i]=0;
			}
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
		int i,j,n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf("%d",&save[i][j]);
		}
		int flag[n+1];
		for(i=0;i<=n;i++)
			flag[i]=0;
		int res=findit(1,n,flag);
		printf("%d\n",res);
	}
	return 0;
}