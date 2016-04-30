#include<iostream>
#include<stdio.h>
using namespace std;

int a[101][101];
int save[101][101];

int max(int a,int b,int c)
{
	return(a>b?(a>c?a:c):(b>c?b:c));
}

int findmax(int i,int j,int n,int m)
{
	if(j<0||i>=n||j>=m||i<0)
		return 0;
	if(save[i][j])
		return save[i][j];
	int temp=(a[i][j]+max(findmax(i+1,j-1,n,m),findmax(i+1,j,n,m),findmax(i+1,j+1,n,m)));
	save[i][j]=temp;
	return temp;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int i;
		int j;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				save[i][j]=0;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&a[i][j]);
		int max=0,temp;
		for(i=0;i<m;i++)
		{
			temp=findmax(0,i,n,m);
			if(temp>max)
				max=temp;
		}
		printf("%d\n",max);
	}
	return 0;
}