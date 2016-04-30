#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long a[n+1],b[n+1];
	a[1]=1;
	b[1]=1;
	int i;
	for(i=2;i<=n;i++)
	{
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
	}
	cout<<a[n]+b[n];
}