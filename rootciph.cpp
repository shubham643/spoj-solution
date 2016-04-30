#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		cout<<a*a-2*b<<endl;
	}
	return 0;
}