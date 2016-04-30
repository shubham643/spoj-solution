#include<bits/stdc++.h>
using namespace std;

/*int ncr(int n,int r)
{
	if(n-r<r)
		r=n-r;
	int save[r+1];
	int i;
	for(i=0;i<=r;i++)
		save[i]=1;
	int j;
	for(i=1;i<n;i++)
	{
		for(j=min(i,r);j>0;j--)
			save[j]+=save[j-1];
	}
	return save[r];
}
*/
/*int findval(int n,int j)
{
	int val=1,temp=n-1,count=n;
	while(count<j)
	{
		count+=temp;
		temp--;
		val++;
	}
	return val;
}
*/
int findit(int n,int k)
{
	int save[k+1][n+1];
	int i,j,l;
	for(i=0;i<=n;i++){
		save[0][i]=1;
	}
	for(i=1;i<=k;i++)
		for(j=0;j<=n;j++)
			save[i][j]=0;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(l=0;l<=j;l++)
			{
				if(i<l)
					break;
				save[i][j]+=save[i-l][j-1];
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
		int n,k;
		scanf("%d%d",&n,&k);
		int res=findit(n-1,k);
		printf("%d\n",res);
	}
	return 0;
}