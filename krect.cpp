#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r,c,k;
	scanf("%d%d%d",&r,&c,&k);
	char save[r][c+1];
	int i,j;
	for(i=0;i<r;i++)
		scanf("%s",save[i]);
	int flag[26];
	for(i=0;i<26;i++)
		flag[i]=0;
	int res=0;
	int count=0;
	list<char> lst;
	int l=0,rt=0;
	while(l<=c-k+1)
	{
		lst.clear();
		for(i=0;i<k&&i<r;i++)
		{
			for(j=l;j<k&&j<c;j++)
			{
				if(flag[save[i][j]-'A']==0)
					count++;
				flag[save[i][j]-'A']++;
				lst.push_back(save[i][j]);
			}
			if(count==k)
				res++;
		}
		for(i=k;i<r;i++)
		{
			for(j=l;j<k;j++)
			{
				if(flag[save[i][j]-'A']==0)
					count++;
				flag[save[i][j]-'A']++;
				lst.push_back(save[i][j]);
				int temp=lst.front();
				if(flag[temp]==1)
					count--;
				flag[temp]--;
				lst.pop_front();
			}
			if(count==k)
				res++;
		}
		l+=k;
		for(i=0;i<26;i++)
			flag[i]=0;
	}
	cout<<res;
}