#include<bits/stdc++.h>
using namespace std;

struct node
{
	int wt,val;
};

node save[505][505];

void findit(int n,int *val,int *wt,int k)
{
	int i,j;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			int with=i>=wt[j]?val[j]+save[i-wt[j]][j-1].val:(save[i][j-1].val);
			int wtwith=i>=wt[j]?wt[j]+save[i-wt[j]][j-1].wt:save[i][j-1].wt;
			int without=save[i][j-1].val;
			int wtwithout=save[i][j-1].wt;
			save[i][j].val=max(with,without);
			if(save[i][j].val==with)
				save[i][j].wt=wtwith;
			else
				save[i][j].wt=wtwithout;
			if(with==without)
				save[i][j].wt=min(wtwith,wtwithout);
		}
	}
	cout<<save[k][n].wt<<" "<<save[k][n].val<<endl;
}

int main()
{
	int n,k;
	while(1){
	scanf("%d%d",&k,&n);
	if(k==0&&n==0)
		break;
	int wt[n+1],val[n+1],i,in=0;
	for(i=1;i<=n;i++){
		++in;
		scanf("%d%d",&wt[in],&val[in]);
		if(val[in]==0)
			in--;
	}
//	cout<<in<<"       ";
	findit(in,val,wt,k);
	}
	return 0;
}