#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long flag[100000];

struct node
{
	bool data;
	long long val;
};

node arr[10010];

void compute(long long n)
{
	long long i,j;
	for(i=2;i*i<=n;i++)
	{
		if(flag[i])
			continue;
		flag[i]=i;
		arr[i].data=true;
		arr[i].val=1;
		for(j=2*i;j<=n;j+=i)
		{
			flag[j]=i;
		}
	}
	for(i;i<=n;i++)
	{
		if(!flag[i])
		{
			flag[i]=i;
			arr[i].data=true;
			arr[i].val=1;
		}
	}
}

void factorise(long long n)
{
	long long i;
	for(i=2;i<=n;i++)
	{
		long long temp=i;
		while(temp!=1)
		{
			if(arr[flag[temp]].val*flag[temp]<=n)
				arr[flag[temp]].val*=flag[temp];
			temp/=flag[temp];
		}
	}
}

int main()
{
	int i;
	for(i=0;i<=10001;i++)
		flag[i]=0;
	compute(10001);
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		long long res=1;
		cin>>n;
		factorise(n);
		for(i=2;i<=n;i++)
		{
			if(arr[i].data)
			{
				res=(res*arr[i].val)%mod;
				arr[i].val=1;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
