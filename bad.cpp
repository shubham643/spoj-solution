#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> v[n+1];
		int total=n*(n-1)/2;
		int i,j;
		for(i=0;i<total;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
		}
		int count[n+1];
		for(i=1;i<=n;i++)
		{
			count[i]=0;
			bool flag[n+1];
			for(j=0;j<=n;j++)
				flag[j]=false;
			queue<int> q;
			for(j=0;j<v[i].size();j++)
			{
				flag[v[i][j]]=true;
				q.push(v[i][j]);
				count[i]++;
			}
			while(!q.empty())
			{
				int temp=q.front();
				q.pop();
				for(j=0;j<v[temp].size();j++)
				{
					if(!flag[v[temp][j]])
					{
						flag[v[temp][j]]=true;
						count[i]++;
					}
				}
			}
		}
		int maxm=0,index=0;
		for(i=1;i<=n;i++){
			if(count[i]>maxm)
			{
				maxm=count[i];
				index=i;
			}
		}
		printf("%d %d\n",index,maxm);
	}
	return 0;
}