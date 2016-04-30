#include<bits/stdc++.h>
using namespace std;

int save[2][5001];

int findit(char *s,int len)
{
	int i,j;
	int l;
	for(l=2;l<=len;l++)
	{
		for(i=0;i<=len-l;i++)
		{
			j=i+l-1;
			if(s[i]==s[j])
				save[i%2][j]=save[(i+1)%2][j-1];
			else
				save[i%2][j]=1+min(save[(i+1)%2][j],save[i%2][j-1]);
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<len;j++)
			cout<<save[i][j]<<" ";
		cout<<endl;
	}
	return save[0][len-1];
}

int main()
{
	int len;
	scanf("%d",&len);
	char s[len+1];
	scanf("%s",s);
	int res=findit(s,len);
	printf("%d",res);
	return 0;
}