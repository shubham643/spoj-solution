#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long m,n;
		set<long long> s;
		scanf("%lld%lld",&m,&n);
		long long i,val;
		for(i=0;i<m;i++)
		{
			scanf("%lld",&val);
			if(val<0){
				val*=-1;
				s.insert(val);
			}
		}
		set<long long>::reverse_iterator ii=s.rbegin();
		long long len=s.size(),res=0;
		i=0;
		while(i<n&&i<len)
		{
			res+=*ii;
			ii++;
			i++;
		}
		cout<<res<<endl;
	}
	return 0;
}