#include<bits/stdc++.h>
#define ll int
using namespace std;

struct node
{
	int value;
	bool flag;
};

int findit(int cap,int n,int *vol,int *val,int *dep)
{
	ll i,j;
	node save[cap+1][n+1];
	for(i=0;i<=cap;i++)
	{
		for(j=0;j<=n;j++)
		{
			save[i][j].value=0;
			save[i][j].flag=false;
		}
	}
	for(i=1;i<=cap;i++)
	{
		for(j=1;j<=n;j++)
		{
			ll with=(i>=vol[j-1])?(val[j-1]*vol[j-1]+save[i-vol[j-1]][j-1].value):(save[i][j-1].value);
			ll without=save[i][j-1].value;
			ll temp=max(with,without);
			if(temp==val[j-1]*vol[j-1]+save[i-vol[j-1]][j-1].value&&dep[j-1]==0)
				save[i][j].flag=true;
			if(temp==val[j-1]*vol[j-1]+save[i-vol[j-1]][j-1].value&&dep[j-1]!=0)
			{
				if(save[i][dep[j-1]-1].flag)
				{
					save[i][j].value=temp;
					save[i][j].flag=false;		
				}
				else
				{
					ll withit=(i>=vol[j-1]+vol[dep[j-1]-1])?(val[j-1]*vol[j-1]+val[dep[j-1]-1]*vol[dep[j-1]-1]+save[i-vol[j-1]-vol[dep[j-1]-1]][j-1].value):(save[i][j-1].value);
					save[i][j].value=max(temp,withit);
					if(save[i][j].value==(val[j-1]*vol[j-1]+val[dep[j-1]-1]*vol[dep[j-1]-1]+save[i-vol[j-1]-vol[dep[j-1]-1]][j-1].value))
					{
						save[i][j].flag=true;
					}
				}
			}
			else
			{
				save[i][j].value=temp;
				save[i][j].flag=false;
			}
		}
	}
	return save[cap][n].value;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int cap,n;
		scanf("%d%d",&cap,&n);
		int i,vol[n],val[n],dep[n];
		for(i=0;i<n;i++)
		{
			scanf("%d%d%d",&vol[i],&val[i],&dep[i]);
		}
		cout<<findit(cap,n,vol,val,dep)<<endl;
	}
	return 0;
}