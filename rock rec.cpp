#include<bits/stdc++.h>
using namespace std;

int save[2005][2005];

int findit(char *s,int st,int en,int *cm)
{
	if(save[st][en])
		return save[st][en];
	if(en==st)
	{
		if(s[st-1]=='1')
			save[st][en]=1;
		else
			save[st][en]= 0;
	}
	else if(en==st+1)
	{
		if(s[st-1]=='1'&&s[st]=='1')
			save[st][en]= 2;
		else if(s[st-1]=='1'||s[st]=='1')
			save[st][en]= 1;
		else 
			save[st][en]= 0;
	}
	else if(en==st+2)
	{
		int res=cm[en]-cm[st-1]>1?3:(cm[en]-cm[st-1]==1?1:0);
		save[st][en]= res;
	}
	else
	{
		int i,sv=0;
		for(i=st;i<en;i++)
		{
			int temp=findit(s,st,i,cm)+findit(s,i+1,en,cm);
			if(temp>sv)
				sv=temp;
		}
		int temp=2*(cm[en]-cm[st-1])>en-st+1?(en-st+1):0;
		if(temp>sv)
			sv=temp;
		save[st][en]=sv;
	}
	return save[st][en];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		char s[n+1];
		scanf("%s",s);
		int cm[n+1];
		cm[0]=0;
		int i,j,k,count=0;
		for(i=1;i<=n;i++)
		{
			if(s[i-1]=='1')
				count++;
			cm[i]=count;
		}
	
		int res=findit(s,1,n,cm);
		printf("%d\n",res);
	}
	return 0;
}