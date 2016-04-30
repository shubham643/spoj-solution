#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
int read_int() {
  char c = gc();
  while(c<'0' || c>'9') c = gc();
  int ret = 0;
  while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
  }
  return ret;
}

int save[2000001][2];

int findit(int n,int *val,int *wt,int k)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(i&1)
		{
			for(j=1;j<=k;j++)
			{
				if(j>=wt[i])
					save[j][1]=max(save[j][0],val[i]+save[j-wt[i]][0]);
				else
					save[j][1]=save[j][0];
			}
		}
		else
		{
			for(j=1;j<=k;j++)
			{
				if(j>=wt[i])
					save[j][0]=max(save[j][1],val[i]+save[j-wt[i]][1]);
				else
					save[j][0]=save[j][1];
			}	
		}
	}
	if(n&1)
		return save[k][1];
	else
		return save[k][0];
}

int main()
{
	int n,k,v,w;
	k=read_int();
	n=read_int();
	int wt[n+1],val[n+1],i,c=0;
	for(i=1;i<=n;i++){
		v=read_int();
		w=read_int();
		if(w<=k)
		{
			wt[++c]=w;
			val[c]=v;
		}
	}
	printf("%d",findit(c,val,wt,k));
	return 0;
}