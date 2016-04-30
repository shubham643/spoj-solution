#include<bits/stdc++.h>
using namespace std;

unsigned long long *save;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long n,k;
		cin>>n>>k;
		k=n-k;
		n-=1;
		if(n-k<k)
			k=n-k;
		unsigned long long save[k+1];
		unsigned long long i,j;
		for(i=0;i<=k;i++)
			save[i]=1;
		for(i=1;i<n;i++)
		{
			for(j=min(i,k);j>0;j--)
			{
				save[j]+=save[j-1];
			}
		}
		cout<<save[k]<<endl;
	}
	return 0;
}