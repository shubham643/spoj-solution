#include<bits/stdc++.h>
using namespace std;

int save[2][5001];

int findit(char *s,int len)
{
	int i,j;
	for(i=len-1;i>=0;i--)
	{
		for(j=i+1;j<len;j++)
		{
			if(s[i]==s[j])
				save[i%2][j]=save[(i+1)%2][j-1];
			else
				save[i%2][j]=1+min(save[i%2][j-1],save[(i+1)%2][j]);
		}
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