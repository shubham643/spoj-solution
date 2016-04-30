#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	set<int> f,res;
	int i;
	for(i=0;i<n;i++)
	{
		int fren;
		scanf("%d",&fren);
		f.insert(fren);
		int count;
		int j;
		scanf("%d",&count);
		for(j=0;j<count;j++)
		{
			int frenfren;
			scanf("%d",&frenfren);
			res.insert(frenfren);
		}
	}
	int ans=0;
	set<int>::iterator ii;
	for(ii=res.begin();ii!=res.end();ii++)
	{
		if(f.find(*ii)==f.end())
			ans++;
	}
	printf("%d",ans);
	return 0;
}