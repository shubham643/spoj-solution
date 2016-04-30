#include<bits/stdc++.h>
using namespace std;

void compute_lps(int lenp,char *p,int *lps)
{
	int i,j;
	int len=0;
	lps[0]=0;
	i=1;
	while(i<lenp)
	{
		if(p[i]==p[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
				len=lps[len-1];
			else
				lps[i++]=0;
		}
	}
}

void kmpalgorithm(string s,char *p,int lens,int lenp)
{
	bool did=false;
	int lps[lenp];
	compute_lps(lenp,p,lps);
	int i=0,j=0;
	while(i<lens)
	{
		if(s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j!=0)
				j=lps[j-1];
			else
				i++;
		}
		if(j==lenp)
		{
			did=true;
			printf("%d\n",i-j);
			j=lps[j-1];
		}
	}
	if(!did)
		printf("\n");
}

int main()
{
	int lenp;
	while(scanf("%d",&lenp)>0)
	{
		int *lps=new int[lenp];
		char *p=new char[lenp+1];
		string s;
		scanf("%s",p);
		cin>>s;
		int lens=s.length();
		if(lenp>lens)
			printf("\n");
		else
			kmpalgorithm(s,p,lens,lenp); 
	}
	return 0;
}