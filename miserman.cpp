#include<bits/stdc++.h>
using namespace std;

int save[105][105];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&save[i][j]);
	int res[n][m];
	for(i=0;i<m;i++)
		res[0][i]=save[0][i];
	for(i=1;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int l,u,r;
			l=(j>0)?(res[i-1][j-1]):INT_MAX;
			u=res[i-1][j];
			r=(j<m-1)?res[i-1][j+1]:INT_MAX;
			res[i][j]=save[i][j]+min(u,min(l,r));
		}
	}
	int ans=INT_MAX;
	for(i=0;i<m;i++)
		if(res[n-1][i]<ans)
			ans=res[n-1][i];
	printf("%d",ans);
	return 0;
}