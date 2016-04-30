#include<bits/stdc++.h>
using namespace std;

int findit(char *s,int n)
{
	int cm[n+1];
	cm[0]=0;
	int save[n+1][n+1];
	int i,j,l,k,count=0;
	for(i=1;i<=n;i++)
	{
		if(s[i-1]=='1')
			count++;
		cm[i]=count;
	}
	for(i=1;i<=n;i++){
		if(s[i-1]=='1')
			save[i][i]=1;
		else
			save[i][i]=0;
	}
	save[0][0]=0;
	for(i=0;i<n-1;i++){
		if(s[i]=='1'&&s[i+1]=='1')
			save[i+1][i+2]=2;
		else if(s[i]=='1'||s[i+1]=='1')
			save[i+1][i+2]=1;
		else
			save[i+1][i+2]=0;
	}
	save[0][1]=0;
	for(i=1;i<=n-2;i++)
		save[i][i+2]=(cm[i+2]-cm[i-1])>1?3:((cm[i+2]-cm[i-1])==1?1:0);
	save[0][2]=0;
	for(l=4;l<=n;l++)
	{
		for(i=1;i<=n-l+1;i++)
		{
			j=l+i-1;
			save[i][j]=0;
			for(k=i;k<j;k++)
			{
				int temp=save[i][k]+save[k+1][j];
				if(temp>save[i][j])
					save[i][j]=temp;
			}
			int temp=(cm[j]-cm[i-1])>l/2?l:0;
			if(temp>save[i][j])
				save[i][j]=temp;
		}
	}
	return save[1][n];
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
		int res=findit(s,n);
		printf("%d\n",res);
	}
	return 0;
}