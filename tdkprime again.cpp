#include<bits/stdc++.h>
using namespace std;

bool flag[100000001];
vector<int> v;
void compute()
{
	int i;
	v.push_back(2);
	for(i=3;i<=10000;i+=2)
	{
		if(!flag[i])
		{
			int temp=i<<1;
			v.push_back(i);
			for(int j=i+temp;j<=100000000;j+=temp)
				flag[j]=true;
		}
	}
	for(i;i<100000000;i+=2)
		if(!flag[i])
			v.push_back(i);
}

int main()
{
	int t;
	cin>>t;
	compute();
	while(t--)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",v[k-1]);
	}
}