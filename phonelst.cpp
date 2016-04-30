#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		bool res=true;
		int n;
		scanf("%d",&n);
		set<long long> s;
		int i;
		long long a[n];
		for(i=0;i<n;i++)
		{
			scanf("%ld",&a[i]);
			s.insert(a[i]);
		}
		set<long long>::reverse_iterator ii;
		for(ii=s.rbegin();ii!=s.rend();ii++)
		{
			if(!res)
				break;
			long long temp=*ii;
			temp/=10;
			while(temp)
			{
				if(s.find(temp)!=s.end())
				{
					res=false;
					break;
				}
				temp/=10;
			}
		}
		if(res)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	return 0;
}