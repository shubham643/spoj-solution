#include<bits/stdc++.h>
using namespace std;

int findmax(int *a,int l,int r)
{
	int save=l,val=-1;
	for(int i=l+1;i<r;i++)
	{
		if(a[i]>val)
		{
			val=a[i];
			save=i;
		}
	}
	return save;
}

int findit(int *x,int *y,int x1,int x2,int y1,int y2,int sx,int sy)
{
	if(x2==x1+1)
		return sy;
	else if(y2==y1+1)
		return sx;
	else
	{
		if(sx>sy)
		{
			int xmax=findmax(x,x1,x2);
			int i;
			int sl=0;
			for(i=xmax+1;i<x2;i++)
				sl+=x[i];
			return x[xmax]+findit(x,y,x1,xmax,y1,y2,sl,sy)+findit(x,y,xmax,x2,y1,y2,sx-sl-x[xmax],sy);
		}
		else
		{
			int ymax=findmax(y,y1,y2);
			int i;
			int sl=0;
			for(i=ymax+1;i<y2;i++)
				sl+=y[i];
			return y[ymax]+findit(x,y,x1,x2,y1,ymax,sx,sl)+findit(x,y,x1,x2,ymax,y2,sx,sy-sl-y[ymax]);
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,sx=0,sy=0;
		scanf("%d%d",&n,&m);
		int y[n+1],x[m+1];
		int i;
		for(i=1;i<n;i++){
			scanf("%d",&y[i]);
			sy+=y[i];
		}
		for(i=1;i<m;i++){
			scanf("%d",&x[i]);
			sx+=x[i];
		}
		int res=findit(x,y,0,m,0,n,sx,sy);
		printf("%d\n",res);
	}
	return 0;
}