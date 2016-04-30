#include<bits/stdc++.h>
using namespace std;

long long doit(long long n,char c,long long val)
{
	switch(c)
	{
		case '+': return n+val;
		case '-': return n-val;
		case '*': return n*val;
		case '/': return n/val;
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,val;
		char c;
		cin>>n>>c>>val;
		n=doit(n,c,val);
		while(1)
		{
			cin>>c;
			if(c=='=')
				break;
			cin>>val;
			n=doit(n,c,val);
		}
		printf("%lld\n",n);
	}
	return 0;
}