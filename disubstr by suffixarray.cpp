#include<bits/stdc++.h>
using namespace std;

struct node
{
	int index;
	int rank[2];
};

bool cmp(node a,node b)
{
	if(a.rank[0]==b.rank[0])
		return a.rank[1]<b.rank[1];
	else
		return a.rank[0]<b.rank[0];
}

void build_suffix(string s,int len,int *sa)
{
	node helper[len];
	int i;
	for(i=0;i<len;i++)
	{
		helper[i].index=i;
		helper[i].rank[0]=s[i];
		helper[i].rank[1]=(i+1<len)?(s[i+1]):-1;
	}
	int ind[len];
	sort(helper,helper+len,cmp);
	int k;
	for(k=4;k<2*len;k=k*2)
	{
		int rank=0;
		int prev_rank=helper[0].rank[0];
		helper[0].rank[0]=rank;
		ind[helper[0].index]=0;
		for(i=1;i<len;i++)
		{
			if(helper[i].rank[0]==prev_rank&&helper[i-1].rank[1]==helper[i].rank[1])
			{
				prev_rank=helper[i].rank[0];
				helper[i].rank[0]=rank;
			}
			else
			{
				prev_rank=helper[i].rank[0];
				helper[i].rank[0]=++rank;	
			}
			ind[helper[i].index]=i;
		}
		for(i=0;i<len;i++)
		{
			int nextindex=helper[i].index+k/2;
			helper[i].rank[1]=(nextindex<len)?(helper[ind[nextindex]].rank[0]):-1;
		}
		sort(helper,helper+len,cmp);
	}
	for(i=0;i<len;i++)
		sa[i]=helper[i].index;
}

void build_lcp(string s,int len,int *sa,int *lcp)
{
	int pos[len];
	int i;
	for(i=0;i<len;i++)
		pos[sa[i]]=i;
	int k=0;
	for(i=0;i<len;i++)
	{
		if(k<0)
			k=0;
		if(pos[i]==len-1)
		{
			k=0;
			lcp[pos[i]]=0;
			continue;
		}
		int next_index=sa[pos[i]+1];
		while(next_index+k<len&&i+k<len&&s[i+k]==s[next_index+k])
			k++;
		lcp[pos[i]]=k;
		k--;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int len=s.length();
		int sa[len];
		build_suffix(s,len,sa);
		int lcp[len];
		build_lcp(s,len,sa,lcp);
		int res=len-sa[0],i;
		for(i=1;i<len;i++)
			res+=len-lcp[i-1]-sa[i];
		printf("%d\n",res);
	}
	return 0;
}