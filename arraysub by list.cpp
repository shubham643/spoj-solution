#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

int a[1000000];
int final[1000000];
list<pp> lst;

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int k;
	scanf("%d",&k);
	for(i=n-1;i>=0;i--)
	{
		pp temp(i,a[i]);
		while(!lst.empty() && lst.back().second<a[i])
			lst.pop_back();
		lst.push_back(temp);
		final[i]=lst.front().second;
		long long end=i+k-1;
		if(lst.front().first>=end)
			lst.pop_front();
	}
	for(i=0;i<n-k+1;i++)
		printf("%d ",final[i]);
	return 0;
}