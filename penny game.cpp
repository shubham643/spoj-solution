#include<bits/stdc++.h>
using namespace std;

int counting[8];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int x;
		for(i=0;i<8;i++)
			counting[i]=0;
		char s[41];
		scanf("%s",s);
		map<char,int> my;
		my['H']=1;
		my['T']=0;
		for(i=0;i<38;i++)
		{
			int p=my[s[i]];
			int q=my[s[i+1]];
			int r=my[s[i+2]];
			counting[r+2*q+4*p]++;
		}
		printf("%d ",n);
		for(i=0;i<8;i++)
			printf("%d ",counting[i]);
		printf("\n");
	}
	return 0;
}