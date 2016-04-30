#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int save[2*n+1][2*n+1];
		int i,j;
		for(i=0;i<=2*n;i++){
			for(j=0;j<=2*n;j++)
			save[i][j]=0;
		}
		set<int> s;
		for(i=0;i<k;i++)
		{
			int val;
			scanf("%d",&val);
			s.insert(val);
		}
		for(i=1;i<=2*n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(i==1&&j==1)
					save[i][j]=1;
				else if(i==1)
					save[i][j]=0;
				else if(s.find(i)!=s.end())
				{
					save[i][j]=(j==0)?0:save[i-1][j-1];
				}
				else
				{
					save[i][j]=((j==0)?0:save[i-1][j-1])+save[i-1][j+1];
				}
			}
		}
/*		for(i=0;i<=2*n;i++)
		{
			for(j=0;j<=2*n;j++)
				cout<<save[i][j]<<" ";
			cout<<endl;
		}
*/		printf("%d\n",save[2*n][0]);
	}
	return 0;
}