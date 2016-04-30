#include<bits/stdc++.h>
using namespace std;

int save[6101][6101];

int findit(string s,int len)
{
	int i,j;
	for(i=0;i<=len;i++)
		save[i][i]=0;
	for(i=2;i<=len;i++)
	{
		for(j=0;j<len-i+1;j++)
		{
			int ending=j+i-1;
			if(s[j]==s[ending])
				save[j][ending]=save[j+1][ending-1];
			else
				save[j][ending]=1+min(save[j+1][ending],save[j][ending-1]);
		}
	}
	return save[0][len-1];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
	string s;
	cin>>s;
	int len=s.length();
	int res=findit(s,len);
	printf("%d\n",res);
	}
	return 0;
}