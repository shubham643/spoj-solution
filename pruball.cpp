#include<bits/stdc++.h>
using namespace std;

int findit(int k,int n)
{
	int save[k+1][n+1];
	int i,j,l;
	for(i=0;i<=n;i++)
	{
		save[1][i]=i;
		save[0][i]=99999999;
	}
	save[0][0]=0;
	for(i=1;i<=k;i++){
		save[i][0]=0;
		save[i][1]=1;
	}
	for(i=2;i<=k;i++)
	{
		for(j=2;j<=n;j++)
		{
			save[i][j]=INT_MAX;
			for(l=1;l<=j;l++)
			{
				int temp=1+max(save[i-1][l-1],save[i][j-l]);
				if(temp<save[i][j])
					save[i][j]=temp;
			}
		}
	}
	return save[k][n];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,k,n;
		scanf("%d%d%d",&i,&k,&n);
		int res=findit(k,n);
		printf("%d %d\n",i,res);
	}
	return 0;
}