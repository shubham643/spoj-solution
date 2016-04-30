#include<bits/stdc++.h>
using namespace std;

int minm(int a,int b,int c)
{
	return min(a,min(b,c));
}

int findit(string a,string b)
{
	int lena=a.length();
	int lenb=b.length();
	int i,j;
	static int save[2001][2001];
	for(i=0;i<=lena;i++)
		save[0][i]=i;
	for(i=0;i<=lenb;i++)
		save[i][0]=i;
	for(i=1;i<=lenb;i++)
	{
		for(j=1;j<=lena;j++)
		{
			int in=save[i-1][j]+1;
			int del=save[i][j-1]+1;
			int edit=save[i-1][j-1]+(b[i-1]!=a[j-1]);
			save[i][j]=minm(in,del,edit);
		}
	}	
	return save[lenb][lena];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int res=findit(a,b);
		printf("%d\n",res);
	}
	return 0;
}